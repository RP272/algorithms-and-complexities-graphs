// aizo-projekt-2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Heap.h"
#include "DijkstraVertex.h"
#include "PrimaVertex.h"

int main()
{
    DijkstraVertex* dv = new DijkstraVertex[5];
    dv[0].set_vertex_id(0);
    dv[0].set_d(10);
    dv[0].set_p(-1);

    dv[1].set_vertex_id(1);
    dv[1].set_d(7);
    dv[1].set_p(-1);

    dv[2].set_vertex_id(2);
    dv[2].set_d(5);
    dv[2].set_p(-1);

    dv[3].set_vertex_id(3);
    dv[3].set_d(3);
    dv[3].set_p(-1);

    dv[4].set_vertex_id(4);
    dv[4].set_d(1);
    dv[4].set_p(-1);

    MinHeap<DijkstraVertex>* heap = new MinHeap<DijkstraVertex>(dv, 5);
    for (int i = 0; i < 5; i++) {
        std::cout << "id: " << dv[i].get_vertex_id() << " d: " << dv[i].get_d() << " p: " << dv[i].get_p() << std::endl;
    }
    std::cout << std::endl;

    PrimaVertex* pv = new PrimaVertex[5];
    pv[0].set_vertex_id(0);
    pv[0].set_key(150);
    pv[0].set_p(-1);

    pv[1].set_vertex_id(1);
    pv[1].set_key(139);
    pv[1].set_p(-1);

    pv[2].set_vertex_id(2);
    pv[2].set_key(55);
    pv[2].set_p(-1);

    pv[3].set_vertex_id(3);
    pv[3].set_key(22);
    pv[3].set_p(-1);

    pv[4].set_vertex_id(4);
    pv[4].set_key(10);
    pv[4].set_p(-1);

    MinHeap<PrimaVertex>* prima_heap = new MinHeap<PrimaVertex>(pv, 5);
    for (int i = 0; i < 5; i++) {
        std::cout << "id: " << pv[i].get_vertex_id() << " key: " << pv[i].get_key() << " p: " << pv[i].get_p() << std::endl;
    }
    std::cout << std::endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
