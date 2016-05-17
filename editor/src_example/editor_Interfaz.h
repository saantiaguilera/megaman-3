/*
 * editor_Interfaz.h
 *
 *  Created on: 29/10/2015
 *      Author: matiaskamien
 */

#ifndef EDITOR_EDITOR_INTERFAZ_H_
#define EDITOR_EDITOR_INTERFAZ_H_
#include <iostream>
#include <string>
#include <gtkmm.h>

//Esta clase va a encapsular la interfaz gráfica del editor.
class Interfaz{
private:
	Glib::RefPtr<Gtk::Builder> builder;

	/*VENTANA INICIAL*/
	Gtk::Window* ventanaInicial;
	//Gtk::Image* imagenInicialEditor;
	Gtk::Button* botonIniciarEditor;
	Gtk::Button* botonSalir;

	/*VENTANA PRINCIPAL*/
	Gtk::Window* ventanaPrincipal;
	Gtk::ScrolledWindow* scrolledWindowNiveles;
	Gtk::TreeView* treeViewNiveles;
	Glib::RefPtr<Gtk::TreeStore> treeModelNiveles;
	Gtk::Button* botonCrearNivel;
	Gtk::Button* botonModificarNivel;
	Gtk::Button* botonEliminarNivel;
	Gtk::Button* botonSalirPrincipal;

	/*VENTANA MODELADO*/
	Gtk::Window* ventanaModelado;
	Gtk::ScrolledWindow* scrWindowModelado;
	Gtk::Button* botonVolverModelado;
	Gtk::Button* botonGuardarCambiosModelado;
	Gtk::Button* botonAgregarConejo;
	Gtk::Button* botonAgregarTortugaRoja;
	Gtk::Button* botonAgregarTortugaVerde;
	Gtk::Button* botonAgregarObstaculoRompible;
	Gtk::Button* botonAgregarObstaculoIrrompible;
	Gtk::Button* botonEliminarImagen;
	Gtk::Button* botonAgregarFinDeNivel;
	Gtk::Button* botonDeshacerClick;
	Gtk::Image* imagenBotonAgregarConejo;
	Gtk::Image* imagenBotonAgregarTortugaRoja;
	Gtk::Image* imagenBotonAgregarTortugaVerde;
	Gtk::Image* imagenBotonAgregarObstaculoIrromp;
	Gtk::Image* imagenBotonAgregarObstaculoRomp;
	Gtk::Image* imagenBotonGuardarCambios;
	Gtk::Image* imagenBotonVolver;
	Gtk::Image* imagenBotonCrearNivel;
	Gtk::Image* imagenBotonEliminarNivel;
	Gtk::Image* imagenBotonSalirPrincipal;
	Gtk::Image* imagenBotonModificarNivel;
	Gtk::Image* imagenBotonEliminarImagen;
	Gtk::Image* imagenBotonIniciarEditor;
	Gtk::Image* imagenBotonSalirEditor;
	Gtk::Image* imagenBotonDeshacerClick;
	Gtk::Image* imagenBotonReajustarTamanio;

	Gtk::Image* imagenTransparenteConejo;
	Gtk::Image* imagenTransparenteTortugaRoja;
	Gtk::Image* imagenTransparenteTortugaVerde;
	Gtk::Image* imagenTransparenteObstaculoRompible;
	Gtk::Image* imagenTransparenteObstaculoIrrompible;
	Gtk::Image* imagenFinDeNivel;
	Gtk::Image* imagenMarcoDeSeleccion;
	Gtk::Image* imagenTransparenteFinDeLlegada;

	Gtk::EventBox* cajaDeEventos;
	Gtk::Fixed* fixed;
	Gtk::Entry* textoCantidadMaxima;
	Gtk::Entry* textoFrecuenciaGeneracion;
	Gtk::Entry* textoNombreNivel;
	Gtk::Entry* entradaAnchoNivel;
	Gtk::Entry* entradaAltoNivel;
	Gtk::HBox* panelCaracteristicas;
	Gtk::Button* botonGuardarPanel;
	Gtk::Button* botonReajustar;

	void conectarBotones();
	void setearImagenesDeBotones(const int alto,const int ancho,const std::string& rutaImagen);
	void setearTooltipText();

public:
	Interfaz();
	~Interfaz();
	void iniciarInterfaz(const char* rutaDelArchivoGlade);
	//getters para los botones que tienen asociada una signal_clicked
	Gtk::Button* obtenerBotonSalir();
	Gtk::Window* obtenerVentanaInicial();
	Gtk::Window* obtenerVentanaPrincipal();
	Gtk::Window* obtenerVentanaModelado();
	Gtk::Button* obtenerBotonCrearNivel();
	Gtk::Button* obtenerBotonEliminarNivel();
	Gtk::Button* obtenerBotonModificarNivel();
	Gtk::Button* obtenerBotonSalirPrincipal();
	Gtk::Button* obtenerBotonVolverModelado();
	Gtk::Button* obtenerBotonIniciarEditor();
	Gtk::Button* obtenerBotonAgregarConejo();
	Gtk::Button* obtenerBotonAgregarTortugaRoja();
	Gtk::Button* obtenerBotonAgregarTortugaVerde();
	Gtk::Button* obtenerBotonDeshacerClick();
	Gtk::Button* obtenerBotonEliminarImagen();
	Gtk::Button* obtenerBotonAgregarFinDeNivel();

	Gtk::Image* obtenerImgTrnConejo();
	Gtk::Image* obtenerImgTrnTortugaRoja();
	Gtk::Image* obtenerImgTrnTortugaVerde();
	Gtk::Image* obtenerImgTrnObsRompible();
	Gtk::Image* obtenerImgTrnObsIrrompible();
	Gtk::Image* obtenerImgMarcoDeSeleccion();
	Gtk::Image* obtenerImgTrnFinDeNivel();

	Gtk::ScrolledWindow* obtenerScrollWindowModelado();
	Gtk::Fixed* obtenerFixed();
	std::string obtenerSeleccionadoComboNivelTexto();
	Gtk::ComboBox* obtenerComboNivel();
	Gtk::EventBox* obtenerCajaDeEventos();
	Gtk::TreeView* obtenerTreeviewNiveles();
	Glib::RefPtr<Gtk::TreeStore>& obtenerModeloTreeview();
	Gtk::HBox* obtenerPanelCaracteristicas();
	Gtk::Entry* obtenerTextoFrecuenciaGeneracion();
	Gtk::Entry* obtenerTextoCantidadMaxima();
	Gtk::Entry* obtenerTextoNombreNivel();
	Gtk::Button* obtenerBotonGuardarPanel();
	Gtk::Button* obtenerBotonGuardarNivel();
	Gtk::Button* obtenerBotonAgregarObstaculoIrrompible();
	Gtk::Button* obtenerBotonAgregarObstaculoRompible();
	Gtk::Button* obtenerBotonReajustarTamanioNivel();
	Gtk::Entry* obtenerEntradaAnchoNivel();
	Gtk::Entry* obtenerEntradaAltoNivel();
};

#endif /* EDITOR_EDITOR_INTERFAZ_H_ */
