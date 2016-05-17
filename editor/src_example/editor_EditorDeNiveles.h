/*
 * editor_EditorDeNiveles.h
 *
 *  Created on: 29/10/2015
 *      Author: matiaskamien
 */

#ifndef EDITOR_EDITOR_EDITORDENIVELES_H_
#define EDITOR_EDITOR_EDITORDENIVELES_H_

#include "../../Common/src/common_XMLHandler.h"
#include "../../Common/src/AdministradorDeNiveles.h"
#include "editor_Interfaz.h"
#include "editor_DragAndDropManager.h"
#include <gtkmm.h>
#include "../../Common/src/constantes.h"
#include "elementos/ElementoVista.h"
#include <X11/Xlib.h>

class EditorDeNiveles{
	private:
		Interfaz interfaz;
		DragAndDropManager dragManager;
		AdministradorDeNiveles administadorNiveles;
		std::string nombreNivelEnModificacion;
		int anchoNivel;
		int altoNivel;
		int anchoNivelDefecto;
		int altoNivelDefecto;

		class ModeloColumnas : public Gtk::TreeModel::ColumnRecord
		{
		public:
			ModeloColumnas()
			{ add(nombreNivel); }

			Gtk::TreeModelColumn<Glib::ustring> nombreNivel;
		};
		ModeloColumnas modeloColumnasNiveles;

		void setearImagenesTransparentes();
		void cargarImagenesTransparentes();

		//contiene todos los metodos que asignan acciones cuando un boton es clickeado
		void asignarAccionesABotones();
		void actualizarComboNiveles();
		void actualizarInformacion();
		void asignarModeloATreeview();
		void clickBotonSalir();
		void clickBotonSalirVentanaPrincipal();
		void clickCrearNivel();
		void clickEliminarNivel();
		void clickModificarNivel();
		void clickBotonIniciarEditor();
		void clickBotonVolverModelado();
		bool clickCajaDeEventos(GdkEventButton* event);
		bool moverMouseEnCajaDeEventos(GdkEventMotion* event);
		bool soltarClickMouseEnCajaDeEventos(GdkEventButton* event);
		void clickAgregarConejo();
		void clickAgregarTortugaRoja();
		void clickAgregarTortugaVerde();
		void clickAgregarObstaculoRompible();
		void clickAgregarObstaculoIrrompible();
		void clickBotonAgregarFinDeNivel();
		void reajustarTamanioNivel();

		void clickDeshacerSeleccionDeBotonera();
		void clickEliminarImagen();
		void clickBotonGuardarPanel();
		void clickBotonGuardarNivel();

		//Devuelve true en caso de que haya una tortuga seleccionada para ver las caracteristicas
		bool textosFrecuenciaYCantidadMaxEditables();

		void actualizarTextosFrecuenciaYCantidadMaxima();

		//Carga el Treeview con los niveles levantados del archivo XML.
		void cargarTreeview();

		//Limpia el modelo del Treeview y lo vuelve a cargar.
		void actualizarTreeview();

		//deshabilita entrada de texto para cantidad maxima y frecuencia generacion
		void deshabilitarTextosFrecuenciaYCantidadMaxima();

		int convertirStringAInt(const std::string& cadena);

		std::string convertirIntAString(int numero)const;

		//Genera un nuevo Elemento vista a partir de un Elemento
		ElementoVista* generarNuevoElementoVista(Elemento* elemento);

		//se setean el ancho y alto que el usuario eligio y en caso de no ser validos sera el ancho y alto default
		void setearAnchoYAltoParaGuardarNivel(int& ancho, int& alto);

		//levantar ancho y alto del nivel. Debe ser invocado al modificar un nivel
		void setearAnchoYAltoAlLevantarNivel();

		//setea ancho y alto por default al crear un nivel.Debe ser invocado cuando se crea un nivel
		void setearAnchoYAltoAlCrearNivel();
	public:
		//Inicia la interfaz gráfica.
		void iniciarInterfaz(const char* rutaDelArchivoGlade);
		EditorDeNiveles();
};

#endif /* EDITOR_EDITOR_EDITORDENIVELES_H_ */
