# EOQ, economic order quantity

## Teoria
Es común que transcurra un lapso de tiempo desde que se hace una orden hasta el momento en que se recibe.
El tiempo entre reabastecimientos consecutivos del inventario se conoce como ciclo, es en este tiempo que se consume la cantidad ordenada Q (nivel máximo de inventario) a una tasa de demanda d.
Se supone que los artículos bajo consideración se sacaran en forma continua a una tasa constante conocida denotada por d; es decir, la demanda es de d unidades por unidad de tiempo.
También se supone que el inventario se reabastece (al producir u ordenar) un lote de tamaño fijo (Q unidades), donde las Q unidades llegan juntas en el tiempo deseado.
En el caso del modelo EOQ básico que se presentara primero, los únicos costos que se consideran son:
* K = costo de preparación para ordenar un lote,
* c = costo unitario de producir o comprar cada unidad,
* h = costo de mantener una unidad en inventario, por unidad de tiempo.
El objetivo consiste en determinar con qué frecuencia y en qué cantidad (Q) se debe reabastecer el inventario de manera que se minimice la suma de estos costos por unidad de tiempo.
La función de costo total del inventario en el modelo EOQ, se compone de:
- Los costos de ordenar ,
- Costos de adquisición del inventario y
- Los costos de mantener inventario por ciclo.

Costo de ordenar: 𝑘
Costos de adquisición del inventario (Q unidades a un costo de ‘c pesos’ cada una): 𝑐𝑄

Costos de mantener inventario: hQ<sup>2</sup>/2d

Entonces el COSTO TOTAL es: 𝑘 + 𝑐𝑄 + hQ<sup>2</sup>/2d

Como la longitud del ciclo es Q/d (tiempo en que se agota el inventario), entonces la función de COSTO TOTAL POR CICLO se divide entre Q/d, esto es:
𝑪𝑻inv (𝑸) =𝒅𝒌/𝑸 + 𝒅𝒄 + 𝒉𝑸/2


## Ejercicio.-
Encuentre el valor __Q__ óptimo (cantidad de piezas a ordenar) que minimice los costos de inventario en el siguiente problema.

Una compañía de taxis privados, consume gasolina a una tasa constante de 10 000 galones por mes.
Debido
a este importante costo, la compañía hace un convenio con una compañía gasolinera para comprar una
cantidad grande de gasolina a precio de descuento de $3.50 por galón cada varios meses.
El costo del convenio, que incluye colocar la gasolina en almacenamiento, es de 2 000 dólares por orden.
El costo de mantener el inventario de gasolina se estima en $0.04 por galón por mes.

La administración desea determinar el tamaño óptimo de orden (Q=número de galones) que minimice los
costos de inventario (𝑪𝑻𝑰𝑵𝑽 (𝑸) ).

* Paso 1.- Determine los valores de los parámetros de la función de costo
* Paso 2.- Encuentre el valor crítico de Q que minimice la función, utilizando un software comercial para derivar y graficar. Muestre el procedimiento siguiendo los pasos vistos en clase y anexe las imágenes.
* Paso 3.- ¿Cuál es el tamaño de lote óptimo?,
¿qué costo conllevaría almacenar dicha cantidad durante un ciclo?
¿Cuánto tiempo tomará para que se agote dicha cantidad de inventario inicial si la demanda no varía?
