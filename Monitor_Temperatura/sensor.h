#ifndef SENSOR_H
#define SENSOR_H

//estrutura responsável por armazenar os valores dos sensores
struct sensor_t
{
    int  CH;
    int  Valor;
    int  Alvo;
    int  Tmin;
    int  Tmax;
    char aceitavel;
    char toleravel;
};

//funções relacionadas aos sensores
void sensor_init        (struct sensor_t *ptr, char ch, int tmin, int tmax, int alvo, char aceitavel, char toleravel);
void sensor_read        (struct sensor_t *ptr, char ch);
void sensor_readAll     (struct sensor_t *ptr, char n);
void sensor_setAlert    (struct sensor_t * ptr, char p);
void sensor_setDanger   (struct sensor_t * ptr, char p);
void sensor_setAlvo     (struct sensor_t * ptr, int alvo);
char sensor_alert       (struct sensor_t * ptr);
char sensor_danger      (struct sensor_t * ptr);
int  sensor_delta       (struct sensor_t * ptr);

#endif