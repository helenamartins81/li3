#include <glib.h>
#include "data.h"
#include "date.h"
#include "postsID.h"
#include "postsD.h"




int compareData(Data a, Data b){

    if (getAno(a) > getAno(a)) return 1;
    else if (getAno(a) < getAno(b)) return -1;
    else if (getMes(a) > getMes(b)) return 1;
    else if (getMes(a) < getMes(b)) return -1;
    else if (getDia(a) > getDia(b)) return 1;
    else if (getDia(a) < getDia(b)) return -1;
    else if (getHora(a) > getHora(b)) return 1;
    else if (getHora(a) < getHora(b)) return -1;
    else if (getMinutos(a) > getMinutos(b)) return 1;
    else if (getMinutos(a) < getMinutos(b)) return -1;
    else return 0;

}

//Compara datas dos stores com as nossas
int compareDate(Date a, Date b){
  if (get_year(a) > get_year(b)) return 1;
  else if (get_year(a) < get_year(b)) return -1;
  else if (get_month(a) > get_month(b)) return 1;
  else if (get_month(a) < get_month(b)) return -1;
  else if (get_day(a) > get_day(b)) return 1;
  else if (get_day(a) < get_day(b)) return -1;
  else return 0;

}


Date converteData(Data a){
  Date d = createDate(getDia(a), getMes(a), getAno(a));
  return d;
}

int dataIgual(Date a, Data b){
  b = converteData(b);
  return(compareDate(a ,b));

}

int data_ord (Posts_D a, Posts_D b){
  return (compareData(getDate(a), getDate(b)));
}

int compareID(Posts_ID a, Posts_ID b){
    if(getUserId2(a) > getUserId2(b))
        return 1;
    else if (getUserId2(a) < getUserId2(b))
        return -1;
    else return 0;
}
