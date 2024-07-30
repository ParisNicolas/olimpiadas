void alarma();
int tempMax;

void inicializar(int temperaturaMaxima) {
    // Acá tenés que hacer la inicialización
    tempMax=temperaturaMaxima;
}

void cambiarTemperatura(int nuevaTemperatura) {
    // Acá tenés que decidir si hacer sonar la alarma o no
    if(nuevaTemperatura > tempMax) alarma();
}
