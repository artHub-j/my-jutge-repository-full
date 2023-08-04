#include <iostream>
#include <sstream>
using namespace std;

#ifndef _CUA_HPP_
#define _CUA_HPP_

class cua
{
public:
    cua();
    cua(const cua &c);
    ~cua();
    cua &operator=(const cua &c);

    void push(int x);
    int pop();
    int primer() const; //front
    int ultim() const;
    bool es_buida() const; //empty
    bool es_plena() const;
    int mida() const;
    void print();

private:
    struct node
    {
        node *seg; //punter al seguent node
        int valor;
    };
    node *_primer, *_ultim;
    int _mida;
};
#endif

cua::cua()
{
    _primer = _ultim = NULL;
    _mida = 0;
}

cua::~cua()
{
    node *aux = _primer;
    node *bor;
    while (aux != NULL)
    {
        bor = aux;
        aux = aux->seg;
        delete bor;
    }
}

void cua::push(int x)
{
    node *n = new node;
    n->valor = x;
    n->seg = NULL;
    if (es_buida())
    {
        _primer = n;
        _ultim = n;
        n->seg = NULL;
        _mida++;
    }
    else
    {
        _ultim->seg = n;
        _ultim = n;
        _mida++;
    }
}

int cua::pop()
{
    //COMPTE cas cua buida no contemplat
    int info = _primer->valor;
    node *bor = _primer;
    if (_primer == _ultim)
    {
        _primer = NULL;
        _ultim = NULL;
        _mida = 0;
    }
    else
    {
        _primer = _primer->seg;
        _mida--;
    }
    delete bor;
    return info;
}

int cua::primer() const
{
    if (_primer != NULL)
    {
        return _primer->valor;
    }
}

int cua::ultim() const
{
    if (_ultim != NULL)
    {
        return _ultim->valor;
    }
}

bool cua::es_buida() const
{
    if (_primer == NULL)
        return true;
    else
        return false;
}

int cua::mida() const
{
    return _mida;
}

void cua::print()
{
    node *aux = _primer;
    while (aux != NULL)
    {
        cout << aux->valor;
        if (aux->seg != NULL)
        {
            cout << " ";
        }
        aux = aux->seg;
    }
}

int main()
{
    int elem;
    int sum = 0;
    cua q, resultat;
    string linia;
    bool primer = true;
    while (getline(cin, linia))
    {
        istringstream ss(linia);
        while (ss >> elem)
        {
            q.push(elem);
        }
        if (q.es_buida())
        {
            cout << endl;
        }
        else
        {
            while (!q.es_buida())
            {
                elem = q.pop();
                if (primer)
                {
                    sum = 0;
                    if (sum >= elem)
                        resultat.push(elem);
                    sum = elem;
                    primer = false;
                }
                else
                {
                    if (sum >= elem)
                        resultat.push(elem);
                    sum = sum + elem;
                }
            }
            if (!resultat.es_buida())
            {
                resultat.print();
            }
            cout << endl;
            while (!resultat.es_buida())
            {
                resultat.pop();
            }
            primer = true;
        }
    }
    return 0;
}