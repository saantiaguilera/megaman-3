/*
Masomenos:


#Lo va a construir el MainScreenController cuando apretas enter sobre la IP.
#Lo joinea el MainScreenController en su destructor (si el trhread es !=NULL)
#que esto va a ocurrir cuando se salga del loop infinito del app->run(w);
constructor(Lista de suscriptores a eventos, ip, port) {
- me guardo la lista
- me connecto con ip port
- dispatcheo evento de que tal me fue (el evento no va a ser mas que un
data model con algun switch para diferenciarlos en el suscriptor)
}

--El socket lo clavo a recibir para siempre?? --
void onReceive() {
- intento parsear alguna respuesta coherente
- dispatcheo un evento de eso
}
*/
