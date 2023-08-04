void print_from_top_to_bottom(stack<int>& pila)
/*  Pre: no és una pila buida */
/*  Post: imprimeix per pantalla la pila entrada pel canal d'entrada de forma que
    el primer element imprès sigui el cap i l'ultim el baix de la pila (d'adalt cap avall). */ 
{
  while(pila.empty()==false)
  {
    cout<<pila.top()<<" ";
    pila.pop();
  }
  cout<<endl;
}
void print_from_bottom_to_top(stack<int>& pila)
/*  Pre: no és una pila buida */
/*  Post: imprimeix per pantalla la pila entrada pel canal d'entrada de forma que
    el primer element imprès sigui el baix i l'ultim el cap de la pila (d'avall cap adalt). */
{
  stack<int> aux;
  while (pila.empty() == false)
  {
    aux.push(pila.top());
    pila.pop();
  }
  print_from_top_to_bottom(aux);
  cout<<endl;
}
