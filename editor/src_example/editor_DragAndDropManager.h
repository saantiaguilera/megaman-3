/*
 * editor_DragAndDropManager.h
 *
 *  Created on: 8/11/2015
 *      Author: nicolasdubiansky
 */

#ifndef EDITOR_SRC_EDITOR_DRAGANDDROPMANAGER_H_
#define EDITOR_SRC_EDITOR_DRAGANDDROPMANAGER_H_
#include <iostream>
#include <vector>
#include <map>
#include "../../Common/src/constantes.h"
#include "elementos/ObstaculoRompibleVista.h"
#include "elementos/ObstaculoIrrompibleVista.h"
#include "elementos/FinDeNivelVista.h"
#include "elementos/GeneradorConejoVista.h"
#include "elementos/GeneradorTortugaVerdeVista.h"
#include "elementos/GeneradorTortugaRojaVista.h"
class DragAndDropManager {
private:
	bool huboDragueo;
	int anchoVentanaDefecto;
	int altoVentanaDefecto;
	std::string claveImagTransparente;
	std::string rutaImagenAInsertar;
	std::vector<ElementoVista*> imagenesParaNivel;
	std::map<std::string, Gtk::Image* > imagenesDeTodosLosObjetosTransparentes;
	Gtk::Fixed* fixed;
	Gtk::Image* marcoImagenSeleccionada;
	ElementoVista* imagenClickeadaParcialmenteParaDraguear;
	ElementoVista* imagenClickeadaParaEliminarOParaVerCaracteristicas;
	bool clickImagenDeBotonera;
	
	//Ajusta las coordenadas del vertice a las coordenada de la cuadricula donde se insertara la imagen
	void ajustarImagenACuadriculaParaInsercion(int &x, int& y);

	//esconde todas las imagenes transparentes evitando su vision en la ventana de dibujo
	void esconderImagenesTransparentes();
	/*esconde todas las imagenes transparentes evitando su vision en la ventana de dibujo
	  salvo la imagen transparente que esta siento usada para draguear dentro de la ventana*/
	void esconderImagenesTransparentesSalvoLaDelDrag();
	//devuelve si es posible dropear una imagen en el lugar deseado al soltar el click del mouse
	//y deja seteado en el parametro msjAMostrarEnCasoError un mensaje en caso de ser falso el retorno
	bool coordenadaValidaParaInsertarImagen(int clickX,int clickY,
			std::string& msjAMostrarEnCasoError)const;
	//recorre todos las imagenes de la ventana de dibujo verificando que no contengan a ningun vertice
	//de la imagen que fue dropeada
	bool verificaSiAlgunVerticeDeImagenADraguearEstaContenidoEnAlgunaImagen(const int& verticeMaximoX,
			const int &verticeMaximoY, const int& verticeMinimoX, const int& verticeMinimoY)const;
	//Devuelve una instancia de alguna clase que herede de Elemento segun la clave de la imagen a insertar
	ElementoVista* crearElementoConcretoSegunClave(const std::string& clave);
	//Carga las imagenes transparentes en la ventana y las esconde
	void cargarImagenesTransparentesEnLaVentana();
	//Devuelve true si ya hay un fin de nivel agregado a la ventana de modelado
	bool yaHayUnFinDeNivelAgregado();
	std::string convertirIntAString(int numero)const;

public:
	DragAndDropManager();

	/*Esconde todas las imagenes transparentes que hay en la ventana de dibujo y ademas setea en NULL
	* los atributos imagenClickeadaParcialmenteParaDraguear y clickImagenDeBotonera.
	* Es recomendable que sea invocado al iniciar la creacion de un nivel o al dropear una imagen
	*/
	void setearImagenMarcoSeleccionada(Gtk::Image* imagen);
	void setearAnchoYAltoPorDefectoDeVentana(const int& ancho,const int& alto);
	void cargarImagenTransparente(const std::string &clave,Gtk::Image* imagen);
	void inicializarDragAndDropManager();

	/* Setea el fixed que esta clase utilizara para realizar el movimiento de imagenes dentro de la
	* ventana de dibujo. Ademas inserta en la ventana las imagenes transparentes en modo hide para su
	* utilizacion a la hora de realizar un movimiento de drag
	*/
	void setearFixed(Gtk::Fixed* fixed);

	//Setea en true el atributo clickImagenDeBotonera. Debe ser invocado cuando un boton de la botonera es clickeado
	void notificarClickEnBotonera();

	/***************************************/
	//Debe ser invocado cuando un boton de la botonera es clickeado. Setea la ruta para cargar la imagen a draguear
	// y la clave que identifica a la imagen Transparente pertenciente a la imagen original.
	void setearRutaParaImagenADraguear(const std::string& claveImagTransp);

	//Debe ser invocado cuando hay un evento de MOUSE MOTION en la ventana de dibujo. Se encarga de mover
	//la imagen transparente cuando se esta dragueando una imagen.
	void mover(const int &x,const int& y);

	//Debe ser invocado cuando hay un evento de MOUSE RELEASE en la ventana de dibujo. Se encarga de insertar
	//la imagen en el lugar donde se solto el click del mouse.
	void drop(int x,int y);

	/*Debe ser invocado cuando se produce un MOUSE CLICK en la ventana de dibujo. Permite identificar si
	*el click fue sobre una imagen ya insertada en la ventana de dibujo
	*seteando el atributo imagenClickeadaParcialmenteParaDraguear
	*/
	void seClickeoSobreUnaImagenInsertada(const int& x,const int& y);

	//Debe ser invocado cuando se clickea el boton de eliminarImagen de la botonera.
	//En caso de haber una imagen clickeada en la ventana,es decir seleccionada, esta sera eliminada
	void eliminarImagenSeleccionada();

	ElementoVista* obtenerImagenSeleccionadaParaVerCaracteristicas();

	~DragAndDropManager();

	const std::vector<ElementoVista*>& obtenerElementos();

	//Agrega un elemento al vector de imagenesParaNivel
	void agregarElemento(ElementoVista* elemento);

	//Carga todas las imagenes del vector imagenesParaNivel en la ventana
	void cargarTodasLasImagenesEnLaVentana();

	//Debe invocarse cuando se clickea el boton de volver a la pantalla principal estando en la del modelado
	void salirDeLaVentana();

	//Debe invocarse cuando se clickea el boton de volver a la pantalla principal estando en la del modelado
	//o para iniciar una modificacion de nivel
	void eliminarTodasLasImagenesDeLaVentana();

	//Debe ser llamado cuando se guardan los nuevos valores de ancho y alto para reajustar la ventana
	//de modelado. Devuelve false en caso de que un elemento quedase fuera de los nuevos limites ingresados.
	//O que sea menor al minimo permitido o mayor al maximo permitido.
	bool esPosibleRedimensionarVentanaModelado(const int& ancho, const int& alto,std::string& msjError);

	//Devuelve true si no hay algun conejo o fin de nivel en la ventana
	bool hayAlgunConejoYFinDeNivel();
};

#endif /* EDITOR_SRC_EDITOR_DRAGANDDROPMANAGER_H_ */
