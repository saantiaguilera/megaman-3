/*
 * editor_Interfaz.cpp
 *
 *  Created on: 29/10/2015
 *      Author: matiaskamien
 */
#include "editor_Interfaz.h"
#include <vector>
#include <string>
#include "../../Common/src/constantes.h"
const std::string modificarNivel("Modificar nivel");
const std::string eliminarNivel("Eliminar nivel");
const std::string rutaImagenBienvenida(RUTA_SERVER_EDITOR_IMAGENES "/jazzRabitEditor.png");
const std::string tooltipAniadirNivel("Añadir nivel");
const std::string tooltipModificarNivel("Modificar nivel");
const std::string tooltipEliminarNivel("Eliminar nivel");
const std::string tooltipSalir("Salir");
const std::string tooltipVolver("Volver");
const std::string tooltipGuardar("Guardar");
const std::string tooltipAgregarConejo("Agregar conejo");
const std::string tooltipAgregarTortugaRoja("Agregar tortuga Roja");
const std::string tooltipAgregarTortugaVerde("Agregar tortuga verde");
const std::string tooltipAgregarFinDeNivel("Agregar punto de finalización de nivel");
const std::string tooltipAgregarObstaculoIrrompible("Agregar obstaculo irrompible");
const std::string tooltipAgregarObstaculoRompible("Agregar obstaculo rompible");
const std::string tooltipEliminarImagenSeleccionada("Elimina la imagen seleccionada");
const std::string tooltipDeshacerSeleccionDeBotonera("Deshace seleccion de botonera");
const std::string tooltipGuardarDatosTortugas("Guarda los datos ingresados para frecuencia y cantidad");
const std::string tooltipReajustarTamanioNivel("Reajustar tamaño del nivel");

Interfaz::Interfaz()
{
	this->ventanaInicial = NULL;
	this->botonSalir = NULL;
	this->botonIniciarEditor = NULL;
	this->ventanaPrincipal = NULL;
	this->botonSalirPrincipal = NULL;
	this->botonCrearNivel = NULL;
	this->ventanaModelado = NULL;
	this->botonVolverModelado = NULL;
	this->botonGuardarCambiosModelado = NULL;
	this->botonModificarNivel = NULL;
	this->botonEliminarNivel  = NULL;
	this->botonAgregarConejo = NULL;
	this->botonAgregarTortugaRoja = NULL;
	this->botonAgregarTortugaVerde = NULL;
	this->imagenBotonAgregarConejo = NULL;
	this->imagenBotonAgregarTortugaRoja = NULL;
	this->imagenBotonAgregarTortugaVerde = NULL;
	this->imagenBotonGuardarCambios = NULL;
	this->imagenBotonCrearNivel = NULL;
	this->imagenBotonVolver = NULL;
	this->imagenBotonEliminarNivel = NULL;
	this->imagenBotonSalirPrincipal = NULL;
	this->imagenBotonModificarNivel = NULL;
	this->cajaDeEventos = NULL;
	this->scrWindowModelado = NULL;
	this->fixed = NULL;
	this->treeViewNiveles = NULL;
	this->scrolledWindowNiveles = NULL;
	this->botonEliminarImagen = NULL;
	this->imagenBotonEliminarImagen = NULL;
	this->botonDeshacerClick = NULL;
	this->textoCantidadMaxima = NULL;
	this->textoFrecuenciaGeneracion = NULL;
	this->panelCaracteristicas=NULL;
	this->botonGuardarPanel=NULL;
	this->textoNombreNivel = NULL;
	this->botonAgregarObstaculoIrrompible=NULL;
	this->botonAgregarObstaculoRompible=NULL;
	this->imagenBotonAgregarObstaculoIrromp=NULL;
	this->imagenBotonAgregarObstaculoRomp=NULL;
	this->imagenBotonIniciarEditor=NULL;
	this->imagenBotonSalirEditor=NULL;
	this->imagenBotonDeshacerClick=NULL;
	this->botonReajustar = NULL;
	this->entradaAltoNivel = NULL;
	this->entradaAnchoNivel = NULL;
	this->imagenBotonReajustarTamanio = NULL;
	this->imagenTransparenteConejo = NULL;
	this->imagenTransparenteTortugaRoja = NULL;
	this->imagenTransparenteTortugaVerde = NULL;
	this->imagenTransparenteObstaculoIrrompible = NULL;
	this->imagenTransparenteObstaculoRompible = NULL;
	this->imagenTransparenteFinDeLlegada = NULL;
	this->imagenMarcoDeSeleccion = NULL;
	this->imagenFinDeNivel=NULL;
	this->botonAgregarFinDeNivel=NULL;
}

void Interfaz::conectarBotones()
{
	Gdk::Color c;
	c.set_rgb_p(0.18,0.07,0.44);
	this->builder->get_widget("ventanaInicio", this->ventanaInicial);
	this->builder->get_widget("botonIniciar",this->botonIniciarEditor);
	this->builder->get_widget("botonSalida",this->botonSalir);
	this->ventanaInicial->modify_bg_pixmap(Gtk::STATE_NORMAL,rutaImagenBienvenida);
	this->botonIniciarEditor->modify_bg(Gtk::STATE_NORMAL,c);
	this->botonSalir->modify_bg(Gtk::STATE_NORMAL,c);

	this->builder->get_widget("ventanaPrincipal", this->ventanaPrincipal);
	this->builder->get_widget("scrolledwindowNiveles", this->scrolledWindowNiveles);
	this->builder->get_widget("treeviewNiveles", this->treeViewNiveles);
	this->builder->get_widget("botonCrearNivel", this->botonCrearNivel);
	this->builder->get_widget("botonModificarNivel",this->botonModificarNivel);
	this->builder->get_widget("botonEliminarNivel",this->botonEliminarNivel);
	this->builder->get_widget("botonSalirPrincipal", this->botonSalirPrincipal);
	this->builder->get_widget("ventanaModelado", this->ventanaModelado);
	this->builder->get_widget("scrWindowModelado", this->scrWindowModelado);
	this->fixed = new Gtk::Fixed();
	this->builder->get_widget("botonGuardarModelado", this->botonGuardarCambiosModelado);
	this->builder->get_widget("botonVolverModelado", this->botonVolverModelado);
	this->builder->get_widget("botonAgregarConejo", this->botonAgregarConejo);
	this->builder->get_widget("botonAgregarTortugaRoja", this->botonAgregarTortugaRoja);
	this->builder->get_widget("botonAgregarTortugaVerde", this->botonAgregarTortugaVerde);
	this->builder->get_widget("imagenAgregarConejo", this->imagenBotonAgregarConejo);
	this->builder->get_widget("imagenAgregarTortuRoja", this->imagenBotonAgregarTortugaRoja);
	this->builder->get_widget("imagenAgregarTortuVerde", this->imagenBotonAgregarTortugaVerde);
	this->builder->get_widget("imagenAgregarObstaculoIrromp1", this->imagenBotonAgregarObstaculoIrromp);
	this->builder->get_widget("imagenAgregarObstaculoRomp", this->imagenBotonAgregarObstaculoRomp);
	this->builder->get_widget("imagenBotonGuardarCambios3", this->imagenBotonGuardarCambios);
	this->builder->get_widget("botonFinNivel", this->botonAgregarFinDeNivel);
	this->builder->get_widget("imagenFinDeNivel", this->imagenFinDeNivel);
	this->builder->get_widget("imagenBotonVolverModelado1", this->imagenBotonVolver);
	this->builder->get_widget("imagenCrearNivel", this->imagenBotonCrearNivel);
	this->builder->get_widget("imagenEliminarNivel", this->imagenBotonEliminarNivel);
	this->builder->get_widget("imagenSalir", this->imagenBotonSalirPrincipal);
	this->builder->get_widget("imagenModificar", this->imagenBotonModificarNivel);
	this->builder->get_widget("cajaEventos", this->cajaDeEventos);
	this->builder->get_widget("botonEliminarImagen", this->botonEliminarImagen);
	this->builder->get_widget("imagenTacho2", this->imagenBotonEliminarImagen);
	this->builder->get_widget("botonDeshacerClick", this->botonDeshacerClick);
	this->builder->get_widget("panelCaracteristicas", this->panelCaracteristicas);
	this->panelCaracteristicas->set_visible(false);
	this->builder->get_widget("textoCantMaxima", this->textoCantidadMaxima);
	this->builder->get_widget("textoFrecGeneracion", this->textoFrecuenciaGeneracion);
	this->builder->get_widget("entradaNombreNivel", this->textoNombreNivel);
	this->builder->get_widget("botonGuardarPanel", this->botonGuardarPanel);
	this->builder->get_widget("botonAgregarObstaculoRomp", this->botonAgregarObstaculoRompible);
	this->builder->get_widget("botonAgregarObstaculoIrromp", this->botonAgregarObstaculoIrrompible);
	this->builder->get_widget("imagenIniciarEditor2", this->imagenBotonIniciarEditor);
	this->builder->get_widget("imagenSalirEditor2", this->imagenBotonSalirEditor);
	this->builder->get_widget("imagenDeshacerClick", this->imagenBotonDeshacerClick);
	this->builder->get_widget("imagenReajustarTamanio", this->imagenBotonReajustarTamanio);

	this->builder->get_widget("botonReajustar", this->botonReajustar);
	this->builder->get_widget("entradaAltoNivel", this->entradaAltoNivel);
	this->builder->get_widget("entradaAnchoNivel", this->entradaAnchoNivel);
	this->cajaDeEventos->add(*fixed);

	this->builder->get_widget("imagenTransparenteConejo", this->imagenTransparenteConejo);
	this->builder->get_widget("imagenTransparenteTRoja", this->imagenTransparenteTortugaRoja);
	this->builder->get_widget("imagenTransparenteTVerde", this->imagenTransparenteTortugaVerde);
	this->builder->get_widget("imagenTransparenteObsIrromp", this->imagenTransparenteObstaculoIrrompible);
	this->builder->get_widget("imagenTransparenteObsRomp", this->imagenTransparenteObstaculoRompible);
	this->builder->get_widget("imagenMarcoDeSeleccion", this->imagenMarcoDeSeleccion);
	this->builder->get_widget("imagenTransparenteFinDeNivel", this->imagenTransparenteFinDeLlegada);
	this->ventanaPrincipal->maximize();
	this->ventanaModelado->maximize();
}

Gtk::Image* Interfaz::obtenerImgTrnConejo()
{
	return this->imagenTransparenteConejo;
}

Gtk::Image* Interfaz::obtenerImgTrnTortugaRoja()
{
	return this->imagenTransparenteTortugaRoja;
}

Gtk::Image* Interfaz::obtenerImgTrnTortugaVerde()
{
	return this->imagenTransparenteTortugaVerde;
}

Gtk::Image* Interfaz::obtenerImgTrnObsRompible()
{
	return this->imagenTransparenteObstaculoRompible;
}

Gtk::Image* Interfaz::obtenerImgTrnFinDeNivel()
{
	return this->imagenTransparenteFinDeLlegada;
}

Gtk::Image* Interfaz::obtenerImgTrnObsIrrompible()
{
	return this->imagenTransparenteObstaculoIrrompible;
}

Gtk::Image* Interfaz::obtenerImgMarcoDeSeleccion()
{
	return this->imagenMarcoDeSeleccion;
}

void Interfaz::iniciarInterfaz(const char* rutaDelArchivoGlade)
{
	this->builder = Gtk::Builder::create_from_file(rutaDelArchivoGlade);
	this->conectarBotones();
	this->setearImagenesDeBotones(100,100,rutaImagenBienvenida);
	this->setearTooltipText();
}

void Interfaz::setearTooltipText()
{
	this->botonCrearNivel->set_tooltip_text(tooltipAniadirNivel);
	this->botonModificarNivel->set_tooltip_text(tooltipModificarNivel);
	this->botonSalirPrincipal->set_tooltip_text(tooltipSalir);
	this->botonVolverModelado->set_tooltip_text(tooltipVolver);
	this->botonEliminarNivel->set_tooltip_text(tooltipEliminarNivel);
	this->botonGuardarCambiosModelado->set_tooltip_text(tooltipGuardar);
	this->botonAgregarConejo->set_tooltip_text(tooltipAgregarConejo);
	this->botonAgregarTortugaRoja->set_tooltip_text(tooltipAgregarTortugaRoja);
	this->botonAgregarTortugaVerde->set_tooltip_text(tooltipAgregarTortugaVerde);
	this->botonAgregarFinDeNivel->set_tooltip_text(tooltipAgregarFinDeNivel);
	this->botonAgregarObstaculoIrrompible->set_tooltip_text(tooltipAgregarObstaculoIrrompible);
	this->botonAgregarObstaculoRompible->set_tooltip_text(tooltipAgregarObstaculoRompible);
	this->botonEliminarImagen->set_tooltip_text(tooltipEliminarImagenSeleccionada);
	this->botonDeshacerClick->set_tooltip_text(tooltipDeshacerSeleccionDeBotonera);
	this->botonGuardarPanel->set_tooltip_text(tooltipGuardarDatosTortugas);
	this->botonReajustar->set_tooltip_text(tooltipReajustarTamanioNivel);
}

void Interfaz::setearImagenesDeBotones(const int alto,const int ancho,const std::string& rutaImagen)
{
	this->imagenBotonAgregarTortugaRoja->set(RUTA_SERVER_EDITOR_IMAGENES SEPARADOR_DIRECTORIOS "tortugaRoja.png");
	this->imagenBotonGuardarCambios->set(RUTA_SERVER_EDITOR_IMAGENES SEPARADOR_DIRECTORIOS "iconoGuardar.png");
	this->imagenBotonVolver->set(RUTA_SERVER_EDITOR_IMAGENES SEPARADOR_DIRECTORIOS "imagenVolver.png");
	this->imagenBotonEliminarNivel->set(RUTA_SERVER_EDITOR_IMAGENES SEPARADOR_DIRECTORIOS "imagenEliminar.png");
	this->imagenBotonCrearNivel->set(RUTA_SERVER_EDITOR_IMAGENES SEPARADOR_DIRECTORIOS "imagenCrearNivel.png");
	this->imagenBotonAgregarTortugaVerde->set(RUTA_SERVER_EDITOR_IMAGENES SEPARADOR_DIRECTORIOS "tortugaVerde.png");
	this->imagenBotonAgregarObstaculoIrromp->set(RUTA_SERVER_EDITOR_IMAGENES SEPARADOR_DIRECTORIOS "iconoParedIrrompible.png");
	this->imagenBotonAgregarObstaculoRomp->set(RUTA_SERVER_EDITOR_IMAGENES SEPARADOR_DIRECTORIOS "obstaculoRomp.png");
	this->imagenFinDeNivel->set(RUTA_SERVER_EDITOR_IMAGENES SEPARADOR_DIRECTORIOS "finDeNivel.png");
	this->imagenBotonSalirPrincipal->set(RUTA_SERVER_EDITOR_IMAGENES SEPARADOR_DIRECTORIOS "imagenSalir.jpg");
	this->imagenBotonModificarNivel->set(RUTA_SERVER_EDITOR_IMAGENES SEPARADOR_DIRECTORIOS "imagenModificar.png");
	this->imagenBotonAgregarConejo->set(RUTA_SERVER_EDITOR_IMAGENES SEPARADOR_DIRECTORIOS "conejo.png");
	this->imagenBotonEliminarImagen->set(RUTA_SERVER_EDITOR_IMAGENES SEPARADOR_DIRECTORIOS "imagenTacho.png");
	this->imagenBotonIniciarEditor->set(RUTA_SERVER_EDITOR_IMAGENES SEPARADOR_DIRECTORIOS "imagenIniciarEditor.png");
	this->imagenBotonSalirEditor->set(RUTA_SERVER_EDITOR_IMAGENES SEPARADOR_DIRECTORIOS "imagenSalirEditor.png");
	this->imagenBotonDeshacerClick->set(RUTA_SERVER_EDITOR_IMAGENES SEPARADOR_DIRECTORIOS "imagenDeshacerClick.png");
	this->imagenBotonReajustarTamanio->set(RUTA_SERVER_EDITOR_IMAGENES SEPARADOR_DIRECTORIOS "imagenReajustarTamanio.png");

	this->imagenBotonAgregarTortugaRoja->set_size_request(80,50);
	this->imagenBotonEliminarImagen->set_size_request(80,50);
	this->imagenBotonReajustarTamanio->set_size_request(70,40);
	this->imagenBotonIniciarEditor->set_size_request(90,70);
	this->imagenFinDeNivel->set_size_request(80,50);
	this->imagenBotonSalirEditor->set_size_request(95,65);
	this->imagenBotonDeshacerClick->set_size_request(80,50);
	this->imagenBotonGuardarCambios->set_size_request(60,30);
	this->imagenBotonVolver->set_size_request(60,30);
	this->imagenBotonModificarNivel->set_size_request(60,30);
	this->imagenBotonEliminarNivel->set_size_request(60,30);
	this->imagenBotonSalirPrincipal->set_size_request(60,30);
	this->imagenBotonCrearNivel->set_size_request(60,30);
	this->imagenBotonAgregarConejo->set_size_request(80,50);
	this->imagenBotonAgregarTortugaVerde->set_size_request(80,50);
	this->imagenBotonAgregarObstaculoIrromp->set_size_request(80,50);
	this->imagenBotonAgregarObstaculoRomp->set_size_request(80,50);
	this->botonAgregarConejo->set_image(*this->imagenBotonAgregarConejo);
	this->botonAgregarTortugaRoja->set_image(*this->imagenBotonAgregarTortugaRoja);
	this->botonAgregarTortugaVerde->set_image(*this->imagenBotonAgregarTortugaVerde);
	this->botonAgregarObstaculoIrrompible->set_image(*this->imagenBotonAgregarObstaculoIrromp);
	this->botonAgregarObstaculoRompible->set_image(*this->imagenBotonAgregarObstaculoRomp);
	this->botonGuardarCambiosModelado->set_image(*this->imagenBotonGuardarCambios);
	this->botonVolverModelado->set_image(*this->imagenBotonVolver);
	this->botonEliminarNivel->set_image(*this->imagenBotonEliminarNivel);
	this->botonCrearNivel->set_image(*this->imagenBotonCrearNivel);
	this->botonAgregarFinDeNivel->set_image(*this->imagenFinDeNivel);
	this->botonSalirPrincipal->set_image(*this->imagenBotonSalirPrincipal);
	this->botonModificarNivel->set_image(*this->imagenBotonModificarNivel);
	this->botonEliminarImagen->set_image(*this->imagenBotonEliminarImagen);
	this->botonIniciarEditor->set_image(*this->imagenBotonIniciarEditor);
	this->botonSalir->set_image(*this->imagenBotonSalirEditor);
	this->botonDeshacerClick->set_image(*this->imagenBotonDeshacerClick);
	this->botonReajustar->set_image(*this->imagenBotonReajustarTamanio);
}

Gtk::Button* Interfaz::obtenerBotonSalir()
{
	return this->botonSalir;
}

Gtk::Button* Interfaz::obtenerBotonAgregarObstaculoIrrompible()
{
	return this->botonAgregarObstaculoIrrompible;
}

Gtk::Button* Interfaz::obtenerBotonAgregarObstaculoRompible()
{
	return this->botonAgregarObstaculoRompible;
}


Gtk::EventBox* Interfaz::obtenerCajaDeEventos()
{
	return this->cajaDeEventos;
}

Gtk::Window* Interfaz::obtenerVentanaPrincipal()
{
	return this->ventanaPrincipal;
}

Gtk::ScrolledWindow* Interfaz::obtenerScrollWindowModelado()
{
	return this->scrWindowModelado;
}


Gtk::Button* Interfaz::obtenerBotonAgregarConejo()
{
	return this->botonAgregarConejo;
}

Gtk::Button* Interfaz::obtenerBotonReajustarTamanioNivel()
{
	return this->botonReajustar;
}

Gtk::Button* Interfaz::obtenerBotonAgregarTortugaRoja()
{
	return this->botonAgregarTortugaRoja;
}

Gtk::Button* Interfaz::obtenerBotonAgregarFinDeNivel()
{
	return this->botonAgregarFinDeNivel;
}


Gtk::Button* Interfaz::obtenerBotonAgregarTortugaVerde()
{
	return this->botonAgregarTortugaVerde;
}

Gtk::Entry* Interfaz::obtenerTextoNombreNivel()
{
	return this->textoNombreNivel;
}

Gtk::Button* Interfaz::obtenerBotonDeshacerClick()
{
	return this->botonDeshacerClick;
}

Gtk::Button* Interfaz::obtenerBotonEliminarImagen()
{
	return this->botonEliminarImagen;
}

Gtk::TreeView* Interfaz::obtenerTreeviewNiveles()
{
	return this->treeViewNiveles;
}

Glib::RefPtr<Gtk::TreeStore>& Interfaz::obtenerModeloTreeview()
{
	return this->treeModelNiveles;
}

Gtk::Fixed* Interfaz::obtenerFixed()
{
	return this->fixed;
}

Gtk::Window* Interfaz::obtenerVentanaModelado()
{
	return this->ventanaModelado;
}

Gtk::Window* Interfaz::obtenerVentanaInicial()
{
	return this->ventanaInicial;
}

Gtk::Button* Interfaz::obtenerBotonCrearNivel()
{
	return this->botonCrearNivel;
}

Gtk::Button* Interfaz::obtenerBotonEliminarNivel()
{
	return this->botonEliminarNivel;
}

Gtk::Button* Interfaz::obtenerBotonModificarNivel()
{
	return this->botonModificarNivel;
}

Gtk::Button* Interfaz::obtenerBotonSalirPrincipal()
{
	return this->botonSalirPrincipal;
}

Gtk::Button* Interfaz::obtenerBotonVolverModelado()
{
	return this->botonVolverModelado;
}


Gtk::Button* Interfaz::obtenerBotonIniciarEditor()
{
	return this->botonIniciarEditor;
}

Gtk::Button* Interfaz::obtenerBotonGuardarNivel()
{
	return this->botonGuardarCambiosModelado;
}
Gtk::HBox* Interfaz::obtenerPanelCaracteristicas()
{
	return this->panelCaracteristicas;
}

Gtk::Entry* Interfaz::obtenerTextoFrecuenciaGeneracion()
{
	return this->textoFrecuenciaGeneracion;
}

Gtk::Entry* Interfaz::obtenerTextoCantidadMaxima()
{
	return this->textoCantidadMaxima;
}
Gtk::Button* Interfaz::obtenerBotonGuardarPanel()
{
	return this->botonGuardarPanel;
}

Gtk::Entry* Interfaz::obtenerEntradaAnchoNivel()
{
	return this->entradaAnchoNivel;
}

Gtk::Entry* Interfaz::obtenerEntradaAltoNivel()
{
	return this->entradaAltoNivel;
}

Interfaz::~Interfaz()
{
	if(this->fixed)
	{
		delete this->fixed;
	}
}

