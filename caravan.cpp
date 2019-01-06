/*-----------------------------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class name here>
 *-----------------------------------------------------------------------------
 * Exercise Number: #exercise_number#
 * File:			caravan.c
 * Author(s):		Peter Bauer
 * Due Date:		#due#
 *-----------------------------------------------------------------------------
 * Description:
 * <your description here>
 *-----------------------------------------------------------------------------
*/
#include <stdlib.h>
#include "caravan.h"
#include "general.h"

typedef struct Node* p_Node;
struct Node
{
  PackAnimal packanimal;
  Node* next;
};

struct CaravanImplementation
{
    int length;
    p_Node head;
};


Caravan new_caravan()
{
  Caravan caravan = (Caravan)malloc(sizeof(CaravanImplementation));
  caravan->length = 0;
  caravan->head = 0;
  return caravan;
}

int get_length(Caravan caravan)
{
  return caravan->length;
}

void delete_caravan(Caravan caravan)
{
  p_Node current = caravan->head;
  while (current != 0)
  {
    p_Node del = current;
    current = current->next;
    sfree(del);
  }
  sfree(caravan);
}

void add_pack_animal(Caravan caravan, PackAnimal animal)
{
  if(animal != 0)
    {
        if(get_caravan(animal) != 0 && get_caravan(animal) != caravan)
        {
            remove_pack_animal(get_caravan(animal), animal);
        }
        p_Node current = caravan->head;
        p_Node n_Animal = (p_Node)malloc(sizeof(struct Node));
        n_Animal->packanimal = animal;
        n_Animal->next = 0;
        if(caravan->head == 0)
        {
            caravan->head = n_Animal;
        }
        else
        {
            while(current->next != 0)
            {
                if(current->packanimal == animal) return;
                current = current->next;
            }
            if(current->packanimal == animal) return;
            current->next = n_Animal;
        }
        add_to_caravan(animal, caravan);
        caravan->length++;
    }
}

void remove_pack_animal(Caravan caravan, PackAnimal animal)
{
  if(animal!=0)
  {
    p_Node current = caravan->head;
    p_Node prev;
    if(current != 0 && current->packanimal == animal)
    {
        caravan->head = current->next;
        remove_from_caravan(animal, caravan);
        sfree(current);
        caravan->length--;
    }
    else
    {
      while(current != 0 && current->packanimal != animal)
      {
          prev = current;
          current = current->next;
      }
      if(current!=0)
      {
        prev->next = current->next;
        remove_from_caravan(animal, caravan);
        sfree(current);
        caravan->length--;
      }
    }
   }
}

int get_caravan_load(Caravan caravan)
{
  p_Node current = caravan->head;
  int load = 0;
  while(current!=0)
  {
      load += get_load(current->packanimal);
      current = current->next;
  }
  return load;
}

void unload(Caravan caravan)
{
  p_Node current = caravan->head;
  while(current != 0)
  {
      unload(current->packanimal);
      current = current->next;
  }
}

int get_caravan_speed(Caravan caravan)
{
  p_Node current = caravan->head;
  int speed = 50;
  while(current!=0)
  {
    if(get_actual_speed(current->packanimal)<speed){
          speed = get_actual_speed(current->packanimal);
      }
      current = current->next;
  }
  return speed;
}
void optimize_load(Caravan caravan)
{

}
