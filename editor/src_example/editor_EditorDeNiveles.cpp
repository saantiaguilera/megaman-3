/*
 * editor_EditorDeNiveles.cpp
 *
 *  Created on: 29/10/2015
 *      Author: matiaskamien
 */
#include "editor_EditorDeNiveles.h"
const std::string mensajeDeCierreVentanaInicial("Cerrando Aplicacion Editor...");
const std::string mensajeDeCierreVentanaPrincipal("Finalizando edicion...");
const std::string debeSeleccionarAlgunNivel("Debe seleccionar algún nivel!");
const std::string debeIngresarNombreDeNivel("Debe ingresar el nombre del nivel!");
const std::string guardadoNivelExitoso("Nivel guardado con exito!");
const std::string guardadoPanelCorrecto("Frecuencia Generacion y Cantidad Maxima guardadas correctamente!");
const std::string guardadoPanelIncorrecto("Primero debe clickear una vez sobre alguna tortuga!");
const std::string guardadoNuevasDimensionesCorrecto("Dimensiones modificadas con exito!");
const std::string debeHaberUnConejoYFinDeLinea("Debe haber algun generador de conejos y un fin de nivel");
const int maximoAnchoYAltoVentanaModelado=3000;
EditorDeNiveles::EditorDeNiveles(){}

void EditorDeNiveles::iniciarInterfaz(const char* rutaDelArchivoGlade)
{
	this->interfaz.iniciarInterfaz(rutaDelArchivoGlade);
	this->setearImagenesTransparentes();
	this->cargarImagenesTransparentes();
	this->asignarModeloATreeview();
	Display* d = XOpenDisplay(NULL);
	Screen*  s = DefaultScreenOfDisplay(d);
	this->anchoNivelDefecto=s->width;
	this->altoNivelDefecto=s->height;
	this->altoNivel = this->altoNivelDefecto;
	this->anchoNivel = this->anchoNivelDefecto;
	if(	this->administadorNiveles.levantarNiveles())
	{
		this->cargarTreeview();
	}
	this->dragManager.setearAnchoYAltoPorDefectoDeVentana(this->anchoNivelDefecto,this->altoNivelDefecto);
	this->dragManager.setearFixed(this->interfaz.obtenerFixed());
	this->asignarAccionesABotones();
	this->interfaz.obtenerVentanaInicial()->show_all();
	this->interfaz.obtenerVentanaInicial()->show_all_children();
	Gtk::Main::run(*this->interfaz.obtenerVentanaInicial());
}

void EditorDeNiveles::cargarImagenesTransparentes()
{
	this->dragManager.cargarImagenTransparente(CONEJO_TRANSP,this->interfaz.obtenerImgTrnConejo());
	this->dragManager.cargarImagenTransparente(TORTUGAROJA_TRANSP,this->interfaz.obtenerImgTrnTortugaRoja());
	this->dragManager.cargarImagenTransparente(TORTUGAVERDE_TRANSP,this->interfaz.obtenerImgTrnTortugaVerde());
	this->dragManager.cargarImagenTransparente(OBSTACULOROMP_TRANSP,this->interfaz.obtenerImgTrnObsRompible());
	this->dragManager.cargarImagenTransparente(FINDENIVEL_TRANSP,this->interfaz.obtenerImgTrnFinDeNivel());
	this->dragManager.cargarImagenTransparente(OBSTACULO_IRROMP_TRANSP,this->interfaz.obtenerImgTrnObsIrrompible());
	this->dragManager.setearImagenMarcoSeleccionada(this->interfaz.obtenerImgMarcoDeSeleccion());
}

void EditorDeNiveles::setearImagenesTransparentes()
{
	this->interfaz.obtenerImgTrnConejo()->set(RUTA_SERVER_EDITOR_IMAGENES SEPARADOR_DIRECTORIOS "conejoTransparente.png");
	this->interfaz.obtenerImgTrnTortugaRoja()->set(RUTA_SERVER_EDITOR_IMAGENES SEPARADOR_DIRECTORIOS "tortugaRojaTransparente.png");
	this->interfaz.obtenerImgTrnTortugaVerde()->set(RUTA_SERVER_EDITOR_IMAGENES SEPARADOR_DIRECTORIOS "tortugaVerdeTransparente.png");
	this->interfaz.obtenerImgTrnObsIrrompible()->set(RUTA_SERVER_EDITOR_IMAGENES SEPARADOR_DIRECTORIOS "obstaculoIrrompibleTransparente.png");
	this->interfaz.obtenerImgTrnObsRompible()->set(RUTA_SERVER_EDITOR_IMAGENES SEPARADOR_DIRECTORIOS "obstaculoRompTransparente.png");
	this->interfaz.obtenerImgMarcoDeSeleccion()->set(RUTA_SERVER_EDITOR_IMAGENES SEPARADOR_DIRECTORIOS "marcoImagenSeleccionada.png");
	this->interfaz.obtenerImgTrnFinDeNivel()->set(RUTA_SERVER_EDITOR_IMAGENES SEPARADOR_DIRECTORIOS "finDeNivelTransparente.png");
}

void EditorDeNiveles::cargarTreeview()
{
	std::vector<std::string> nombreNiveles = this->administadorNiveles.nombreNiveles();
	std::vector<std::string>::iterator it;
	for(it = nombreNiveles.begin(); it != nombreNiveles.end(); ++it)
	{
		Gtk::TreeModel::Row row = *(this->interfaz.obtenerModeloTreeview()->append());
		row[this->modeloColumnasNiveles.nombreNivel] = (*it);
	}
	this->interfaz.obtenerTreeviewNiveles()->set_model(this->interfaz.obtenerModeloTreeview());
}

void EditorDeNiveles::asignarAccionesABotones()
{
	this->interfaz.obtenerBotonSalir()->signal_clicked().connect(sigc::mem_fun(*this,&EditorDeNiveles::clickBotonSalir));
	this->interfaz.obtenerBotonCrearNivel()->signal_clicked().connect(sigc::mem_fun(*this,&EditorDeNiveles::clickCrearNivel));
	this->interfaz.obtenerBotonEliminarNivel()->signal_clicked().connect(sigc::mem_fun(*this,&EditorDeNiveles::clickEliminarNivel));
	this->interfaz.obtenerBotonModificarNivel()->signal_clicked().connect(sigc::mem_fun(*this,&EditorDeNiveles::clickModificarNivel));
	this->interfaz.obtenerBotonSalirPrincipal()->signal_clicked().connect(sigc::mem_fun(*this,&EditorDeNiveles::clickBotonSalirVentanaPrincipal));
	this->interfaz.obtenerBotonIniciarEditor()->signal_clicked().connect(sigc::mem_fun(*this,&EditorDeNiveles::clickBotonIniciarEditor));
	this->interfaz.obtenerBotonVolverModelado()->signal_clicked().connect(sigc::mem_fun(*this,&EditorDeNiveles::clickBotonVolverModelado));
	this->interfaz.obtenerCajaDeEventos()->set_events(Gdk::ALL_EVENTS_MASK);
	this->interfaz.obtenerCajaDeEventos()->signal_button_press_event().connect(sigc::mem_fun(*this, &EditorDeNiveles::clickCajaDeEventos));
	this->interfaz.obtenerCajaDeEventos()->signal_motion_notify_event().connect(sigc::mem_fun(*this, &EditorDeNiveles::moverMouseEnCajaDeEventos));
	this->interfaz.obtenerCajaDeEventos()->signal_button_release_event().connect(sigc::mem_fun(*this, &EditorDeNiveles::soltarClickMouseEnCajaDeEventos));
	this->interfaz.obtenerBotonAgregarConejo()->signal_clicked().connect(sigc::mem_fun(*this, &EditorDeNiveles::clickAgregarConejo));
	this->interfaz.obtenerBotonAgregarTortugaRoja()->signal_clicked().connect(sigc::mem_fun(*this, &EditorDeNiveles::clickAgregarTortugaRoja));
	this->interfaz.obtenerBotonAgregarTortugaVerde()->signal_clicked().connect(sigc::mem_fun(*this, &EditorDeNiveles::clickAgregarTortugaVerde));
	this->interfaz.obtenerBotonAgregarObstaculoRompible()->signal_clicked().connect(sigc::mem_fun(*this, &EditorDeNiveles::clickAgregarObstaculoRompible));
	this->interfaz.obtenerBotonAgregarObstaculoIrrompible()->signal_clicked().connect(sigc::mem_fun(*this, &EditorDeNiveles::clickAgregarObstaculoIrrompible));
	this->interfaz.obtenerBotonDeshacerClick()->signal_clicked().connect(sigc::mem_fun(*this, &EditorDeNiveles::clickDeshacerSeleccionDeBotonera));
	this->interfaz.obtenerBotonEliminarImagen()->signal_clicked().connect(sigc::mem_fun(*this, &EditorDeNiveles::clickEliminarImagen));
	this->interfaz.obtenerBotonGuardarPanel()->signal_clicked().connect(sigc::mem_fun(*this, &EditorDeNiveles::clickBotonGuardarPanel));
	this->interfaz.obtenerBotonGuardarNivel()->signal_clicked().connect(sigc::mem_fun(*this, &EditorDeNiveles::clickBotonGuardarNivel));
	this->interfaz.obtenerBotonReajustarTamanioNivel()->signal_clicked().connect(sigc::mem_fun(*this, &EditorDeNiveles::reajustarTamanioNivel));
	this->interfaz.obtenerBotonAgregarFinDeNivel()->signal_clicked().connect(sigc::mem_fun(*this, &EditorDeNiveles::clickBotonAgregarFinDeNivel));

}

void EditorDeNiveles::reajustarTamanioNivel()
{
	int anchoAReajustar=this->convertirStringAInt(this->interfaz.obtenerEntradaAnchoNivel()->get_text());
	int altoAReajustar=this->convertirStringAInt(this->interfaz.obtenerEntradaAltoNivel()->get_text());
	std::string msjError="";
	if(this->dragManager.esPosibleRedimensionarVentanaModelado(anchoAReajustar,altoAReajustar,msjError))
	{
		this->altoNivel = altoAReajustar;
		this->anchoNivel = anchoAReajustar;
		this->interfaz.obtenerCajaDeEventos()->set_size_request(anchoAReajustar,altoAReajustar);
		Gtk::MessageDialog msjExitoso(guardadoNuevasDimensionesCorrecto);
		msjExitoso.run();
	}else{
		Gtk::MessageDialog msjConError(msjError);
		msjConError.run();
		this->interfaz.obtenerEntradaAnchoNivel()->set_text(this->convertirIntAString(this->anchoNivel));
		this->interfaz.obtenerEntradaAltoNivel()->set_text(this->convertirIntAString(this->altoNivel));
	}

}

void EditorDeNiveles::setearAnchoYAltoAlCrearNivel()
{
	this->altoNivel = this->altoNivelDefecto;
	this->anchoNivel = this->anchoNivelDefecto;
	this->interfaz.obtenerEntradaAltoNivel()->set_text
				(this->convertirIntAString(this->altoNivel));
	this->interfaz.obtenerEntradaAnchoNivel()->set_text
				(this->convertirIntAString(this->anchoNivel));
	this->interfaz.obtenerCajaDeEventos()->set_size_request(this->anchoNivel,this->altoNivel);

}

void EditorDeNiveles::setearAnchoYAltoAlLevantarNivel()
{
	int anchoAReajustar=this->convertirStringAInt(this->interfaz.obtenerEntradaAnchoNivel()->get_text());
	int altoAReajustar=this->convertirStringAInt(this->interfaz.obtenerEntradaAltoNivel()->get_text());
	this->interfaz.obtenerCajaDeEventos()->set_size_request(anchoAReajustar,altoAReajustar);
}


void EditorDeNiveles::clickBotonAgregarFinDeNivel()
{
	this->dragManager.notificarClickEnBotonera();
	this->interfaz.obtenerPanelCaracteristicas()->set_visible(false);
	this->dragManager.setearRutaParaImagenADraguear(FINDENIVEL_TRANSP);
}

void EditorDeNiveles::setearAnchoYAltoParaGuardarNivel(int& ancho, int& alto)
{
	if(this->anchoNivelDefecto > ancho || this->altoNivelDefecto > alto
			|| maximoAnchoYAltoVentanaModelado < ancho || maximoAnchoYAltoVentanaModelado < alto)
	{
		ancho = this->anchoNivelDefecto;
		alto = this->altoNivelDefecto;
	}
	this->anchoNivel = ancho;
	this->altoNivel = alto;

}

void EditorDeNiveles::clickBotonGuardarNivel()
{
	std::vector<ElementoVista*>::const_iterator it;
	std::string nombreNivel = this->interfaz.obtenerTextoNombreNivel()->get_text();
	if(nombreNivel.length() > 0)
	{
		if(this->dragManager.hayAlgunConejoYFinDeNivel())
		{
			int anchoSetadoPorUsuario =this->convertirStringAInt(this->interfaz.obtenerEntradaAnchoNivel()->get_text());
			int altoSeteadoPorUsuario=this->convertirStringAInt(this->interfaz.obtenerEntradaAltoNivel()->get_text());
			this->setearAnchoYAltoParaGuardarNivel(anchoSetadoPorUsuario,altoSeteadoPorUsuario);
			Nivel nivel(nombreNivel,this->anchoNivel,this->altoNivel);
			for(it = this->dragManager.obtenerElementos().begin();
					it != this->dragManager.obtenerElementos().end(); ++it)
			{
				nivel.agregarElemento((*it)->obtenerElemento()->obtenerCopia());
			}
			if(this->nombreNivelEnModificacion != nivel.obtenerNombre())
			{
				this->administadorNiveles.eliminarNivelDelMapYDelXML(this->nombreNivelEnModificacion);
			}
			//nivel.guardarNivel();//ver q asi no se guardaria mas
			this->administadorNiveles.guardarNivel(nivel);
			this->nombreNivelEnModificacion=nivel.obtenerNombre();
			this->administadorNiveles.agregarNivelCopia(nivel);
			Gtk::MessageDialog msjExitoso(guardadoNivelExitoso);
			msjExitoso.run();
		}else{
			Gtk::MessageDialog msjError(debeHaberUnConejoYFinDeLinea);
					msjError.run();
		}
	}else{
		Gtk::MessageDialog msjError(debeIngresarNombreDeNivel);
		msjError.run();
	}
}

void EditorDeNiveles::clickAgregarObstaculoRompible()
{
	this->dragManager.notificarClickEnBotonera();
	this->interfaz.obtenerPanelCaracteristicas()->set_visible(false);
	this->dragManager.setearRutaParaImagenADraguear(OBSTACULOROMP_TRANSP);
}

void EditorDeNiveles::clickAgregarObstaculoIrrompible()
{
	this->dragManager.notificarClickEnBotonera();
	this->interfaz.obtenerPanelCaracteristicas()->set_visible(false);
	this->dragManager.setearRutaParaImagenADraguear(OBSTACULO_IRROMP_TRANSP);
}

void EditorDeNiveles::clickAgregarConejo()
{
	this->dragManager.notificarClickEnBotonera();
	this->interfaz.obtenerPanelCaracteristicas()->set_visible(false);
	this->dragManager.setearRutaParaImagenADraguear(CONEJO_TRANSP);
}

void EditorDeNiveles::clickAgregarTortugaRoja()
{
	this->dragManager.notificarClickEnBotonera();
	this->interfaz.obtenerPanelCaracteristicas()->set_visible(false);
	this->dragManager.setearRutaParaImagenADraguear(TORTUGAROJA_TRANSP);
}

void EditorDeNiveles::clickAgregarTortugaVerde()
{
	this->dragManager.notificarClickEnBotonera();
	this->interfaz.obtenerPanelCaracteristicas()->set_visible(false);
	this->dragManager.setearRutaParaImagenADraguear(TORTUGAVERDE_TRANSP);
}

void EditorDeNiveles::clickDeshacerSeleccionDeBotonera()
{
	this->dragManager.inicializarDragAndDropManager();
	this->interfaz.obtenerPanelCaracteristicas()->set_visible(false);
}

void EditorDeNiveles::clickEliminarImagen()
{
	this->dragManager.eliminarImagenSeleccionada();
	this->interfaz.obtenerPanelCaracteristicas()->set_visible(false);
}
void EditorDeNiveles::clickCrearNivel()
{
	this->interfaz.obtenerVentanaPrincipal()->hide();
	this->interfaz.obtenerTextoNombreNivel()->set_text("");
	this->dragManager.inicializarDragAndDropManager();
	this->setearAnchoYAltoAlCrearNivel();
	Gtk::Main::run(*this->interfaz.obtenerVentanaModelado());
}

void EditorDeNiveles::clickBotonVolverModelado()
{
	this->nombreNivelEnModificacion="";
	this->dragManager.salirDeLaVentana();
	this->actualizarTextosFrecuenciaYCantidadMaxima();
	this->interfaz.obtenerVentanaModelado()->hide();
	this->actualizarTreeview();
	this->interfaz.obtenerVentanaPrincipal()->show_all();
	Gtk::Main::run(*this->interfaz.obtenerVentanaPrincipal());
}

void EditorDeNiveles::actualizarTreeview()
{
	this->interfaz.obtenerModeloTreeview().clear();
	this->interfaz.obtenerModeloTreeview() = Gtk::TreeStore::create(this->modeloColumnasNiveles);
	this->cargarTreeview();
}

void EditorDeNiveles::clickEliminarNivel()
{
	Glib::RefPtr<Gtk::TreeSelection> selection = this->interfaz.obtenerTreeviewNiveles()->get_selection();
	Gtk::TreeModel::iterator iter = selection->get_selected();
	if(iter)
	{
		Gtk::TreeModel::Row row = *iter;
		Glib::ustring nombreNivel = row[this->modeloColumnasNiveles.nombreNivel];
		std::string nombreNivelEnString = nombreNivel;
		this->administadorNiveles.eliminarNivelDelMapYDelXML(nombreNivelEnString);
		this->actualizarTreeview();
	}else{
		Gtk::MessageDialog msjError(debeSeleccionarAlgunNivel);
		msjError.run();
}
}

void EditorDeNiveles::clickModificarNivel()
{
	Glib::RefPtr<Gtk::TreeSelection> selection = this->interfaz.obtenerTreeviewNiveles()->get_selection();
	Gtk::TreeModel::iterator iter = selection->get_selected();
	if(iter)
{
		Gtk::TreeModel::Row row = *iter;
		Glib::ustring nombreNivel = row[this->modeloColumnasNiveles.nombreNivel];
		std::string nombreNivelEnString = nombreNivel;
		this->nombreNivelEnModificacion=nombreNivelEnString;
		Nivel* nivelAModificar=this->administadorNiveles.obtenerPunteroANivel(nombreNivelEnString);
		this->interfaz.obtenerTextoNombreNivel()->set_text(nombreNivelEnString);
		this->interfaz.obtenerEntradaAltoNivel()->set_text
				(this->convertirIntAString(nivelAModificar->obtenerAltoNivel()));
		this->interfaz.obtenerEntradaAnchoNivel()->set_text
				(this->convertirIntAString(nivelAModificar->obtenerAnchoNivel()));
		this->dragManager.eliminarTodasLasImagenesDeLaVentana();
		this->setearAnchoYAltoAlLevantarNivel();
		std::vector<Elemento*>::const_iterator it;
		for(it = nivelAModificar->obtenerElementos().begin();
				it != nivelAModificar->obtenerElementos().end(); ++it)
		{
			ElementoVista* elemento = this->generarNuevoElementoVista((*it));
			this->dragManager.agregarElemento(elemento);
		}

		std::vector<GeneradorTortuga*>::const_iterator itTortu;
		for(itTortu = nivelAModificar->obtenerTortugas().begin();
				itTortu != nivelAModificar->obtenerTortugas().end(); ++itTortu)
		{
			ElementoVista* elemento = this->generarNuevoElementoVista((*itTortu));
			this->dragManager.agregarElemento(elemento);
		}

		std::vector<GeneradorConejo*>::const_iterator itConejo;
		for(itConejo = nivelAModificar->obtenerConejos().begin();
				itConejo != nivelAModificar->obtenerConejos().end(); ++itConejo)
		{
			ElementoVista* elemento = this->generarNuevoElementoVista((*itConejo));
			this->dragManager.agregarElemento(elemento);
		}
		this->interfaz.obtenerVentanaPrincipal()->hide();
		this->dragManager.inicializarDragAndDropManager();
		this->dragManager.cargarTodasLasImagenesEnLaVentana();
		Gtk::Main::run(*this->interfaz.obtenerVentanaModelado());
	}else{
		Gtk::MessageDialog msjError(debeSeleccionarAlgunNivel);
		msjError.run();
	}
}

ElementoVista* EditorDeNiveles::generarNuevoElementoVista(Elemento* elemento)
{
	ElementoVista* elementoADevolver = NULL;
	std::string tipoElemento = elemento->obtenerTipoElemento();
	if(tipoElemento == CONEJO)
	{
		elementoADevolver = new GeneradorConejoVista();
		elementoADevolver->copiarInformacion(elemento);
	}else{
		if(tipoElemento == TORTUGAROJA)
		{
			elementoADevolver = new GeneradorTortugaRojaVista();
			elementoADevolver->copiarInformacion(elemento);
		}else{
			if(tipoElemento == TORTUGAVERDE)
			{
				elementoADevolver = new GeneradorTortugaVerdeVista();
				elementoADevolver->copiarInformacion(elemento);
			}else{
				if(tipoElemento == FINDENIVEL)
				{
					elementoADevolver = new FinDeNivelVista();
					elementoADevolver->copiarInformacion(elemento);
				}else{
					if(tipoElemento == OBSTACULOROMP)
					{
						elementoADevolver = new ObstaculoRompibleVista();
						elementoADevolver->copiarInformacion(elemento);
					}else{
						if(tipoElemento == OBSTACULO_IRROMP)
						{
							elementoADevolver = new ObstaculoIrrompibleVista();
							elementoADevolver->copiarInformacion(elemento);
						}
					}
				}
			}
		}
	}
	return elementoADevolver;
}

bool EditorDeNiveles::moverMouseEnCajaDeEventos(GdkEventMotion* event)
{
	int xClick = event->x;
	int yClick = event->y;
	this->dragManager.mover(xClick,yClick);
	return true;
}
void EditorDeNiveles::clickBotonGuardarPanel()
{
	if((this->textosFrecuenciaYCantidadMaxEditables())
		&&(!this->interfaz.obtenerTextoCantidadMaxima()->get_text().empty())
		&&(!this->interfaz.obtenerTextoFrecuenciaGeneracion()->get_text().empty()))
	{
	  GeneradorTortugaVista* tortugaSeleccionada=(GeneradorTortugaVista*)(this->dragManager.obtenerImagenSeleccionadaParaVerCaracteristicas());
	  int frecuenciaGeneracion=this->convertirStringAInt(this->interfaz.obtenerTextoFrecuenciaGeneracion()->get_text());
	  int cantidadMaxima=this->convertirStringAInt(this->interfaz.obtenerTextoCantidadMaxima()->get_text());
	  GeneradorTortuga* tortugaSeleccionadaAtributo=(GeneradorTortuga*)tortugaSeleccionada->obtenerElemento();
	  tortugaSeleccionadaAtributo->setCantidadMaxima(cantidadMaxima);
	  tortugaSeleccionadaAtributo->setFrecuenciaGeneracion(frecuenciaGeneracion);
	  Gtk::MessageDialog msjExitoso(guardadoPanelCorrecto);
	  msjExitoso.run();
	}else{
		Gtk::MessageDialog msjError(guardadoPanelIncorrecto);
		msjError.run();
	}
}
int EditorDeNiveles::convertirStringAInt(const std::string& cadena)
{
	  std::stringstream convertidor(cadena);
	  int numero;
	  convertidor >> numero;
	  return numero;
}


std::string EditorDeNiveles::convertirIntAString(int numero)const
{
	std::string stringConvertido;
	std::stringstream convertidor;
	convertidor << numero;
	stringConvertido=convertidor.str();
	return stringConvertido;
}
void EditorDeNiveles::actualizarTextosFrecuenciaYCantidadMaxima()
{
	if(this->textosFrecuenciaYCantidadMaxEditables())
	{
		this->interfaz.obtenerVentanaModelado()->set_size_request(850,625);
		this->interfaz.obtenerPanelCaracteristicas()->set_visible(true);
		ElementoVista* tortugaSeleccionada=this->dragManager.obtenerImagenSeleccionadaParaVerCaracteristicas();
		GeneradorTortugaVista* tortuga=(GeneradorTortugaVista*)tortugaSeleccionada;
		GeneradorTortuga* tortugaAtributo = (GeneradorTortuga*)tortuga->obtenerElemento();
		this->interfaz.obtenerTextoFrecuenciaGeneracion()->set_text
				(this->convertirIntAString(tortugaAtributo->obtenerFrecuenciaGeneracion()));
		this->interfaz.obtenerTextoCantidadMaxima()->set_text
				(this->convertirIntAString(tortugaAtributo->obtenerCantidadMaxima()));
	}else{
		this->deshabilitarTextosFrecuenciaYCantidadMaxima();
	}

}
void EditorDeNiveles::deshabilitarTextosFrecuenciaYCantidadMaxima()
{
	this->interfaz.obtenerPanelCaracteristicas()->set_visible(false);
}

bool EditorDeNiveles::clickCajaDeEventos(GdkEventButton* event)
{
	int xClick = event->x;
	int yClick = event->y;
	this->dragManager.seClickeoSobreUnaImagenInsertada(xClick,yClick);
	this->actualizarTextosFrecuenciaYCantidadMaxima();
	return true;
}

bool EditorDeNiveles::textosFrecuenciaYCantidadMaxEditables()
{
	if(!this->dragManager.obtenerImagenSeleccionadaParaVerCaracteristicas())
	{
		return false;
	}else{
		return(this->dragManager.obtenerImagenSeleccionadaParaVerCaracteristicas()->obtenerElemento()
				->obtenerClaveImagenTransparente()==TORTUGAROJA_TRANSP
				||this->dragManager.obtenerImagenSeleccionadaParaVerCaracteristicas()->obtenerElemento()
				->obtenerClaveImagenTransparente()==TORTUGAVERDE_TRANSP);
	}
}

bool EditorDeNiveles::soltarClickMouseEnCajaDeEventos(GdkEventButton* event)
{
	int xClick = event->x;
	int yClick = event->y;
	this->dragManager.drop(xClick,yClick);
	this->actualizarTextosFrecuenciaYCantidadMaxima();
	return true;
}

void EditorDeNiveles::clickBotonIniciarEditor()
{
	this->interfaz.obtenerVentanaInicial()->hide();
	this->interfaz.obtenerVentanaPrincipal()->show_all();
	Gtk::Main::run(*this->interfaz.obtenerVentanaPrincipal());
}

void EditorDeNiveles::asignarModeloATreeview()
{
	this->interfaz.obtenerModeloTreeview() = Gtk::TreeStore::create(this->modeloColumnasNiveles);
	this->interfaz.obtenerTreeviewNiveles()->set_model(this->interfaz.obtenerModeloTreeview());
	this->interfaz.obtenerTreeviewNiveles()->append_column("Niveles", this->modeloColumnasNiveles.nombreNivel);
	this->interfaz.obtenerTreeviewNiveles()->set_reorderable();
}

void EditorDeNiveles::clickBotonSalir()
{
	Gtk::MessageDialog message2(mensajeDeCierreVentanaInicial);
	message2.run();
	this->interfaz.obtenerVentanaInicial()->hide();
	Gtk::Main::quit();
}

void EditorDeNiveles::clickBotonSalirVentanaPrincipal()
{
	Gtk::MessageDialog message2(mensajeDeCierreVentanaPrincipal);
	message2.run();
	this->interfaz.obtenerVentanaPrincipal()->hide();
	Gtk::Main::quit();
}
