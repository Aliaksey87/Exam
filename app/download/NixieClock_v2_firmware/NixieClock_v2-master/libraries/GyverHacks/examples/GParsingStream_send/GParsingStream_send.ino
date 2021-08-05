/*
   Данный алгоритм позволяет получить через Serial пачку значений, и раскидать
   их в целочисленный массив. Использовать можно банально для управления
   ЧЕМ УГОДНО через bluetooth, так как bluetooth модули есть UART интерфейс связи.
   Либо управлять через Serial с какой-то программы с ПК.
   Парсинг не блокирующий, не содержит while и delay, не мешает работе основного скетча
   НО ОН ЧИТАЕТ ВЕСЬ ТРАФИК ИЗ ПОРТА!
   Как использовать:
   1) В PARSE_AMOUNT указывается, какое количество значений мы хотим принять.
   От этого значения напрямую зависит размер массива принятых данных, всё просто
   2) Пакет данных на приём должен иметь вид:
   Начало - символ $
   Разделитель - пробел
   Завершающий символ - ;
   Пример пакета: $110 25 600 920;  будет раскидан в массив intData согласно порядку слева направо
   Что делает данный скетч:
   Принимает пакет данных указанного выше вида, раскидывает его в массив intData, затем выводит обратно в порт.
   Отличие от предыдущего примера: алгоритм запрятан в GParsingStream.h, входит в пак GyverHacks
   Доступны и подсвечиваются функции parsingStream и dataReady
   Скачать можно здесь: https://github.com/AlexGyver/GyverLibs
*/

#define PARSE_AMOUNT 5         // число значений в массиве, который хотим получить
int intData[PARSE_AMOUNT];     // массив численных значений после парсинга

#include "GParsingStream.h"

void setup() {
  Serial.begin(9600);
}

void loop() {
  parsingStream((int*)&intData);               // функция парсинга, парсит в массив!

  if (dataReady()) {                           // если получены данные
    sendPacket((int*)&intData, sizeof(intData));  // отправить обратно в виде пакета
  }
}
