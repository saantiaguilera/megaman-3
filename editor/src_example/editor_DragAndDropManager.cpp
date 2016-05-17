/*
 * editor_DragAndDropManager.cpp
 *
 *  Created on: 8/11/2015
 *      Author: nicolasdubiansky
 */

#include "editor_DragAndDropManager.h"
#include <gtkmm/fixed.h>
#include <gtkmm/image.h>
#include <gtkmm/messagedialog.h>
#include <string>
const int mitadAnchoYAltoImagen=28;
const int ajusteEntreMarcoEImagen=3;
const int maximoAnchoYAltoVentanaModelado=3000;
const std::string yaExisteFinDeNivel("Ya existe un fin de nivel.Solo puede haber uno por nivel");

DragAndDropManager::DragAndDropManager()
{
	this->fixed=NULL;
	this->marcoImagenSeleccionada=NULL;
	this->imagenClickeadaParcialmenteParaDraguear=NULL;
	this->clickImagenDeBotonera=false;
	this->claveImagTransparente ="";
	this->rutaImagenAInsertar="";
	this->huboDragueo=false;
	this->imagenClickeadaParaEliminarOParaVerCaracteristicas=NULL;
}

void DragAndDropManager::inicializarDragAndDropManager()
{
	this->imagenClickeadaParcialmenteParaDraguear=NULL;
	this->claveImagTransparente="";
	this->clickImagenDeBotonera=false;
	this->esconderImagenesTransparentes();
}

void DragAndDropManager::setearImagenMarcoSeleccionada(Gtk::Image* imagen)
{
	this->marcoImagenSeleccionada = imagen;
}

void DragAndDropManager::cargarImagenTransparente(const std::string &clave,Gtk::Image* imagen)
{
	this->imagenesDeTodosLosObjetosTransparentes[clave] = imagen;
}

void DragAndDropManager::setearFixed(Gtk::Fixed* fixed)
{
	this->fixed=fixed;
	this->cargarImagenesTransparentesEnLaVentana();
}

void DragAndDropManager::cargarImagenesTransparentesEnLaVentana()
{
	this->fixed->put(*this->marcoImagenSeleccionada,1000,1000);
	std::map<std::string, Gtk::Image*>::iterator itTransp;
	for(itTransp=this->imagenesDeTodosLosObjetosTransparentes.begin();
			itTransp != this->imagenesDeTodosLosObjetosTransparentes.end(); ++itTransp) {
		this->fixed->put(*((*itTransp).second),1000,1000);
		(*itTransp).second->hide();
	}
}

void DragAndDropManager::esconderImagenesTransparentes()
{
	std::map<std::string, Gtk::Image*>::iterator itTransp;
	for(itTransp=this->imagenesDeTodosLosObjetosTransparentes.begin();
			itTransp != this->imagenesDeTodosLosObjetosTransparentes.end(); ++itTransp) {
		(*itTransp).second->hide();
	}
	this->marcoImagenSeleccionada->hide();
}

void DragAndDropManager::esconderImagenesTransparentesSalvoLaDelDrag()
{
	this->marcoImagenSeleccionada->hide();
	std::map<std::string, Gtk::Image*>::iterator itTransp;
	for(itTransp=this->imagenesDeTodosLosObjetosTransparentes.begin();
			itTransp != this->imagenesDeTodosLosObjetosTransparentes.end(); ++itTransp) {
		if((*itTransp).first!=this->claveImagTransparente)
		{
			(*itTransp).second->hide();
		}
	}
}

void DragAndDropManager::mover(const int &x,const int& y)
{
	if(this->clickImagenDeBotonera || this->imagenClickeadaParcialmenteParaDraguear)
	{
		this->huboDragueo=true;

		if(this->clickImagenDeBotonera)
		{

			this->fixed->move(*(this->imagenesDeTodosLosObjetosTransparentes.find(this->claveImagTransparente)->second),
					x-mitadAnchoYAltoImagen,y-mitadAnchoYAltoImagen);
		}else{
			this->fixed->move(*(this->imagenesDeTodosLosObjetosTransparentes.find
			(this->imagenClickeadaParcialmenteParaDraguear->obtenerElemento()->obtenerClaveImagenTransparente())->second),
					x-mitadAnchoYAltoImagen,y-mitadAnchoYAltoImagen);
		}
		this->fixed->show_all();
		this->esconderImagenesTransparentesSalvoLaDelDrag();
	}
}

bool DragAndDropManager::coordenadaValidaParaInsertarImagen(int clickX,int clickY,
		std::string& msjAMostrarEnCasoError)const
{
	if(clickX<0 || clickY<0)
	{
		msjAMostrarEnCasoError="Inserte imagen dentro de la ventana de dibujo";
		return false;
	}
	bool algunVerticeEstaContenido=false;
	if(!this->claveImagTransparente.empty())
	{
		if(this->imagenClickeadaParaEliminarOParaVerCaracteristicas && !this->huboDragueo)
		{
			//esto es porque si el click para drop fue sobre la imagen sin drag, es decir para seleccion
			//se necesita el vertice superior izquierdo de la imagen, y no el click de drop para calcular
			//ya que sino la validacion daria que otra imagen contiene a la imagen seleccionada, porque
			//la coordenada del click no es la misma que la del vertice superior izquierdo de la imagen selecc
			clickX = this->imagenClickeadaParaEliminarOParaVerCaracteristicas->obtenerElemento()->obtenerVerticeX();
			clickY=this->imagenClickeadaParaEliminarOParaVerCaracteristicas->obtenerElemento()->obtenerVerticeY();
		}
		int anchoImagen=this->imagenesDeTodosLosObjetosTransparentes.find(this->claveImagTransparente)->second->get_width();
			int altoImagen=this->imagenesDeTodosLosObjetosTransparentes.find(this->claveImagTransparente)->second->get_height();
			int verticeMaximoX=clickX+anchoImagen;
			int verticeMaximoY=clickY+altoImagen;
			int verticeMinimoX=clickX;
			int verticeMinimoY=clickY;
			algunVerticeEstaContenido = this->verificaSiAlgunVerticeDeImagenADraguearEstaContenidoEnAlgunaImagen
				(verticeMaximoX,verticeMaximoY,verticeMinimoX,verticeMinimoY);
	}else{
		return false;
	}

	if(algunVerticeEstaContenido)
	{
		msjAMostrarEnCasoError="Ya existe una imagen en el lugar deseado";
		return false;
	}else{return true;}
}

bool DragAndDropManager::verificaSiAlgunVerticeDeImagenADraguearEstaContenidoEnAlgunaImagen(const int& verticeMaximoX,
		const int &verticeMaximoY, const int& verticeMinimoX, const int& verticeMinimoY)const
{
	std::vector<ElementoVista*>::const_iterator itImagenes;
		for(itImagenes=this->imagenesParaNivel.begin();
					itImagenes != this->imagenesParaNivel.end(); ++itImagenes)	{
		//para que no se tome en cuenta si es la misma imagen para comparar los vertices
		if(this->imagenClickeadaParcialmenteParaDraguear!=(*itImagenes))
		{
			//se deben preguntar por los cuatro vertices de la imagen transparente si alguno esta dentro la imagen del iterador
			if( ((*itImagenes)->areaDeImagenContieneACoordenada(verticeMinimoX,verticeMinimoY)) ||
				((*itImagenes)->areaDeImagenContieneACoordenada(verticeMaximoX,verticeMinimoY)) ||
				((*itImagenes)->areaDeImagenContieneACoordenada(verticeMinimoX,verticeMaximoY)) ||
				((*itImagenes)->areaDeImagenContieneACoordenada(verticeMaximoX,verticeMaximoY)) )
			{
				//no se puede insertar la imagen porque algun vertice esta contenido en alguna imagen ya insertada
				return true;
			}
		}
	}
	return false;
}

ElementoVista* DragAndDropManager::crearElementoConcretoSegunClave(const std::string& clave)
{
	//SEGUN LA CLAVE CREAR OBJETO CONCRETO, VER DE HACER CON EL MAP Y TYPEDEF COMO EL CLIENTHANDLER
	if(clave==CONEJO_TRANSP)
	{
		return new GeneradorConejoVista();
	}
	if(clave==TORTUGAROJA_TRANSP)
	{
		return new GeneradorTortugaRojaVista();
	}
	if(clave==TORTUGAVERDE_TRANSP)
	{
		return new GeneradorTortugaVerdeVista();
	}
	if(clave==OBSTACULOROMP_TRANSP)
	{
		return new ObstaculoRompibleVista();
	}
	if(clave==OBSTACULO_IRROMP_TRANSP)
	{
		return new ObstaculoIrrompibleVista();
	}
	if(clave==FINDENIVEL_TRANSP)
	{
		return new FinDeNivelVista();
	}
	return NULL;
}

bool DragAndDropManager::hayAlgunConejoYFinDeNivel()
{
	bool hayConejo=false;
	bool hayFinDeNivel=false;
	std::vector<ElementoVista*>::iterator itImagenes;
	for(itImagenes=this->imagenesParaNivel.begin();
					itImagenes != this->imagenesParaNivel.end(); ++itImagenes)
		{
			if((*itImagenes)->obtenerElemento()->obtenerTipoElemento()==CONEJO)
			{
				hayConejo=true;
			}
			if((*itImagenes)->obtenerElemento()->obtenerTipoElemento()==FINDENIVEL)
			{
				hayFinDeNivel=true;
			}
		}
	return (hayConejo && hayFinDeNivel);
}

void DragAndDropManager::drop(int x,int y)
{
	this->ajustarImagenACuadriculaParaInsercion(x,y);
	std::string mensajeEnCasoDeErrorAlInsertar="";
	if(this->coordenadaValidaParaInsertarImagen(x,y,mensajeEnCasoDeErrorAlInsertar))
	{
		if(!this->imagenClickeadaParcialmenteParaDraguear)
		{
			if(this->clickImagenDeBotonera)
			{
				if(this->yaHayUnFinDeNivelAgregado()&&this->claveImagTransparente==FINDENIVEL_TRANSP)
				{
					this->inicializarDragAndDropManager();
					Gtk::MessageDialog yaExisteFinNivelMsj(yaExisteFinDeNivel);
					yaExisteFinNivelMsj.run();
				}
				else
				{
					ElementoVista* imagenAInsertar;
					imagenAInsertar=this->crearElementoConcretoSegunClave(this->claveImagTransparente);
					imagenAInsertar->obtenerElemento()->setearVerticeSupIzqAreaImagen(x,y);
					imagenAInsertar->obtenerElemento()->setearClaveImagenTransparente(this->claveImagTransparente);
					this->imagenesParaNivel.push_back(imagenAInsertar);
					this->fixed->put(*imagenAInsertar->obtenerImagen(),x,y);
					this->fixed->move(*(imagenesDeTodosLosObjetosTransparentes.find(this->claveImagTransparente)->second),x,y);
					this->fixed->show_all();
					if(imagenAInsertar->obtenerElemento()->obtenerClaveImagenTransparente()!=OBSTACULOROMP_TRANSP
							&& imagenAInsertar->obtenerElemento()->obtenerClaveImagenTransparente()!=OBSTACULO_IRROMP_TRANSP)
					{
						//no se inserto ningun obstaculo asi que no hay que darle la chance de seguir
						//dropeando imagenes sin volver a clickear en la botonera
						this->huboDragueo=false;
						this->inicializarDragAndDropManager();
					}
					this->esconderImagenesTransparentesSalvoLaDelDrag();
					this->imagenClickeadaParaEliminarOParaVerCaracteristicas = imagenAInsertar;
					this->marcoImagenSeleccionada->show();
					this->fixed->move(*this->marcoImagenSeleccionada,
							this->imagenClickeadaParaEliminarOParaVerCaracteristicas->obtenerElemento()->obtenerVerticeX()-ajusteEntreMarcoEImagen,
							this->imagenClickeadaParaEliminarOParaVerCaracteristicas->obtenerElemento()->obtenerVerticeY()-ajusteEntreMarcoEImagen);
				}
			}
		}
		else
		{
			if(this->huboDragueo)
			{
				//SI ENTRA ACA ES PORQUE SE PUEDE REALIZAR EL DROP DE LA IMAGEN EN LA NUEVA POSICION
				this->imagenClickeadaParcialmenteParaDraguear->obtenerElemento()->setearVerticeSupIzqAreaImagen(x,y);
				this->fixed->move(*this->imagenClickeadaParcialmenteParaDraguear->obtenerImagen(),x,y);
				this->fixed->move(*(this->imagenesDeTodosLosObjetosTransparentes.find
						(this->imagenClickeadaParcialmenteParaDraguear->obtenerElemento()->obtenerClaveImagenTransparente())->second),x,y);
				this->huboDragueo=false;
				this->fixed->show_all();
				this->inicializarDragAndDropManager();
				this->imagenClickeadaParaEliminarOParaVerCaracteristicas=NULL;
			}
			else{
				//SI ENTRA ACA ES PORQUE ESTA EN LA SITUACION QUE SE CLICKEO UNA VEZ SOBRE UNA IMAGEN
				//SIN DRAGUEARLA, ES DECIR SE SELECCIONO PARA ELIMINARLA O VER CARACTERISTICAS
				this->inicializarDragAndDropManager();
				this->marcoImagenSeleccionada->show();
				this->fixed->move(*this->marcoImagenSeleccionada,
						this->imagenClickeadaParaEliminarOParaVerCaracteristicas->obtenerElemento()->obtenerVerticeX()-ajusteEntreMarcoEImagen,
						this->imagenClickeadaParaEliminarOParaVerCaracteristicas->obtenerElemento()->obtenerVerticeY()-ajusteEntreMarcoEImagen);
			}
		}
	}
	else
	{
		if(!mensajeEnCasoDeErrorAlInsertar.empty() && this->huboDragueo)
		{
			Gtk::MessageDialog msjAdvertencia(mensajeEnCasoDeErrorAlInsertar);
			//lo hago aca tambien porque sino cuando aparece el cartel, si moves mouse sigue la imagen transp
			this->inicializarDragAndDropManager();
			msjAdvertencia.run();
		}
		this->inicializarDragAndDropManager();
		this->huboDragueo=false;
		this->imagenClickeadaParaEliminarOParaVerCaracteristicas=NULL;
	}
}

void DragAndDropManager::ajustarImagenACuadriculaParaInsercion(int &x, int& y)
{
	int ancho = this->imagenesDeTodosLosObjetosTransparentes.find
			(this->claveImagTransparente)->second->get_width();
	int alto =this->imagenesDeTodosLosObjetosTransparentes.
			find(this->claveImagTransparente)->second->get_height();
	int deltaX=x/ancho;
	int deltaY=y/alto;
	x = (x/ancho)* ancho + deltaX;
	y = (y/alto)* alto + deltaY;
}

const std::vector<ElementoVista*>& DragAndDropManager::obtenerElementos()
{
	return this->imagenesParaNivel;
}

void DragAndDropManager::setearRutaParaImagenADraguear(const std::string& claveImagTransp)
{
	this->claveImagTransparente=claveImagTransp;
}

void DragAndDropManager::seClickeoSobreUnaImagenInsertada(const int& x,const int& y)
{
	ElementoVista* imagenEncontrada = NULL;
	unsigned int iterador = 0;
	while(iterador < this->imagenesParaNivel.size() && imagenEncontrada==NULL)
	{
		imagenEncontrada = this->imagenesParaNivel[iterador]->areaDeImagenContieneACoordenada(x,y);
		++iterador;
	}
	if((imagenEncontrada != NULL)&&(!this->clickImagenDeBotonera))
	{
		this->imagenClickeadaParcialmenteParaDraguear = imagenEncontrada;
		this->imagenClickeadaParaEliminarOParaVerCaracteristicas=imagenEncontrada;
		this->claveImagTransparente=this->imagenClickeadaParcialmenteParaDraguear->obtenerElemento()->obtenerClaveImagenTransparente();
	}
	else{
		this->imagenClickeadaParcialmenteParaDraguear=NULL;
		this->imagenClickeadaParaEliminarOParaVerCaracteristicas=NULL;
	}
}
void DragAndDropManager::notificarClickEnBotonera()
{
	this->clickImagenDeBotonera=true;
	this->esconderImagenesTransparentes();
}

void DragAndDropManager::eliminarImagenSeleccionada()
{
	if(this->imagenClickeadaParaEliminarOParaVerCaracteristicas)
	{
		this->imagenClickeadaParaEliminarOParaVerCaracteristicas->obtenerImagen()->hide();
		std::vector<ElementoVista*>::iterator itImagenes;
		std::vector<ElementoVista*>::iterator itEliminador;
		for(itImagenes=this->imagenesParaNivel.begin();
					itImagenes != this->imagenesParaNivel.end(); ++itImagenes)
		{
			if((*itImagenes)==this->imagenClickeadaParaEliminarOParaVerCaracteristicas)
			{
				itEliminador=itImagenes;
			}
		}
		delete(this->imagenClickeadaParaEliminarOParaVerCaracteristicas);
		this->imagenClickeadaParaEliminarOParaVerCaracteristicas=NULL;
		this->imagenesParaNivel.erase(itEliminador);
		this->marcoImagenSeleccionada->hide();
	}
	else{
		Gtk::MessageDialog msjAdvertencia("Debe seleccionar una imagen y luego hacer click en el boton para eliminarla");
		msjAdvertencia.run();
	}
}

void DragAndDropManager::setearAnchoYAltoPorDefectoDeVentana(const int& ancho,const int& alto)
{
	this->anchoVentanaDefecto = ancho;
	this->altoVentanaDefecto = alto;
}

bool DragAndDropManager::esPosibleRedimensionarVentanaModelado
(const int& ancho, const int& alto,std::string& msjError)
{
	if(this->anchoVentanaDefecto>ancho || this->altoVentanaDefecto>alto
			|| maximoAnchoYAltoVentanaModelado < ancho || maximoAnchoYAltoVentanaModelado < alto)
	{
		msjError= "ERROR: Minimo ancho: " +this->convertirIntAString(anchoVentanaDefecto)
				+".Minimo alto: "+this->convertirIntAString(this->altoVentanaDefecto)+
				". Maximo ancho/alto: "+this->convertirIntAString(maximoAnchoYAltoVentanaModelado)+".";
		return false;
	}
	std::vector<ElementoVista*>::iterator itImagenes;
	for(itImagenes=this->imagenesParaNivel.begin();
				itImagenes != this->imagenesParaNivel.end(); ++itImagenes)
	{
		int altoImagen=(*itImagenes)->obtenerImagen()->get_height();
		int anchoImagen=(*itImagenes)->obtenerImagen()->get_width();
		int verticeInferiorDerechoX =(*itImagenes)->obtenerElemento()->obtenerVerticeX()+anchoImagen;
		int verticeInferiorDerechoY= (*itImagenes)->obtenerElemento()->obtenerVerticeX()+altoImagen;
		if(verticeInferiorDerechoX > ancho || verticeInferiorDerechoY>alto)
		{
			//si entra aca es porque alguna imagen quedaria fuera de los limites nuevos propuestos por el usuario
			msjError="ERROR: Alguna imagen de la ventana quedaria fuera con sus nuevas dimensiones.";
			return false;
		}
	}
	return true;
}

std::string DragAndDropManager::convertirIntAString(int numero)const
{
	std::string stringConvertido;
	std::stringstream convertidor;
	convertidor << numero;
	stringConvertido=convertidor.str();
	return stringConvertido;
}

bool DragAndDropManager::yaHayUnFinDeNivelAgregado()
{
	std::vector<ElementoVista*>::iterator itImagenes;
	for(itImagenes=this->imagenesParaNivel.begin();
				itImagenes != this->imagenesParaNivel.end(); ++itImagenes)
	{
		if((*itImagenes)->obtenerElemento()->obtenerTipoElemento()==FINDENIVEL)
		{
			return true;
		}
	}
	return false;
}

void DragAndDropManager::eliminarTodasLasImagenesDeLaVentana()
{
	std::vector<ElementoVista*>::iterator itImagenes;
	for(itImagenes=this->imagenesParaNivel.begin();
				itImagenes != this->imagenesParaNivel.end(); ++itImagenes)
	{
		(*itImagenes)->obtenerImagen()->hide();
		delete(*itImagenes);
	}
	this->imagenesParaNivel.clear();
}

void DragAndDropManager::cargarTodasLasImagenesEnLaVentana()
{
	std::vector<ElementoVista*>::iterator it;
	for(it=this->imagenesParaNivel.begin();
				it != this->imagenesParaNivel.end(); ++it) {
		this->fixed->put(*((*it)->obtenerImagen()),(*it)->obtenerElemento()->obtenerVerticeX(),(*it)->obtenerElemento()->obtenerVerticeY());
	}
	this->fixed->show_all();
	this->esconderImagenesTransparentes();
}

void DragAndDropManager::agregarElemento(ElementoVista* elemento)
{
	this->imagenesParaNivel.push_back(elemento);
}

ElementoVista* DragAndDropManager::obtenerImagenSeleccionadaParaVerCaracteristicas()
{
	return this->imagenClickeadaParaEliminarOParaVerCaracteristicas;
}
void DragAndDropManager::salirDeLaVentana()
{
	this->eliminarTodasLasImagenesDeLaVentana();
	this->inicializarDragAndDropManager();
	this->imagenClickeadaParaEliminarOParaVerCaracteristicas=NULL;
}

DragAndDropManager::~DragAndDropManager()
{
	std::vector<ElementoVista*>::iterator itImagenes;
	for(itImagenes=this->imagenesParaNivel.begin();
				itImagenes != this->imagenesParaNivel.end(); ++itImagenes) {
		if(*itImagenes)
		{
			delete(*itImagenes);
		}
	}
	if(this->marcoImagenSeleccionada)
	{
		delete this->marcoImagenSeleccionada;
	}
}
