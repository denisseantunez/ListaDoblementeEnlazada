## NOTA:
Preguntarle a Irene que tan estricta va a ser con la eficiencia,
por ejemplo, en el metodo Ordenar uso el metodo ObtenerEnPos, pero
este metodo recorre toda la lista hasta llegar a la posicion. Pero
el metodo Ordenar usa mucho este metodo, por lo que sería mas 
eficiente accesar a estos valores con manualmente con un puntero,
para evitar recorrer la lista cada vez
---

# TODO:
F - fácil, (3/5)  
M - Mas o menos fácil, (4/8)  
D - Díficil, (2/2)  
Total: 8/16

_Por hacer_
- [ ] Hacer que la denisse use el tab con 2 espacios - D <---- jajajajajaja porque dificiiiilll
- [ ] Documentar el código - F
- [ ] Generar la documentación - F
- [ ] Bitácora - M

_Métodos que faltan:_
- [x] Agregar en pos - M
- [x] Eliminar en pos - M
- [x] Imprimir lista en reversa - F
- [x] Acceder a un elemento (operador[]) - M
```c++
Lista[i] = 5;
```
- [x] Ordenar de forma ascendente ([puntero a funcion](https://www.geeksforgeeks.org/function-pointer-in-cpp/)) D
- [x] Intercambiar una lista con otro - F
- [ ] Transferir elementos de una lista a otra
	- [ ] Todos los elementos - M
	- [ ] Los elementos desde una posición hasta otra (o desde un indice a otro) - M
    - [ ] Los elementos a partir de cierta posición (o índice) - M
    - NOTA: Preguntar si con transferir los elementos de una lista a otra, se refiere
    a borrarlos de la lista recibida por parametro, y agregarlos a lista original, o
    algo así. Y como los agregamos? al final o al inicio?

_Métodos de eliminar especiales:_
- [x] Toda ocurrencia de un elemento - M
- [x] Todo elemento que cumpla cierta condición (puntero a funcion) - D
- [x] Todo elemento repetido - F
