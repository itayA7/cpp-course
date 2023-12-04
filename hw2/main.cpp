#include <iostream>
#include "PairOfShoes.h"
#include "ShoeStorage.h"
#include "ShoeStore.h"

using namespace std;
int main()
{

    /*
    ShoeStorage st;

    PairOfShoes sh("adidas", 15);
    st.AddPairOfShoes(sh);

    PairOfShoes sh2("jordan", 50);
    st.AddPairOfShoes(sh2);

    PairOfShoes sh3("nike", 20);
    st.AddPairOfShoes(sh3);

    PairOfShoes sh4("puma", 12);
    st.AddPairOfShoes(sh4);

    cout << st.AverageShoePrice() << endl;
    cout << st.GetPrice("jordan") << endl;
    cout << st.GetPrice("nike") << endl;
    st.RemovePairOfShoes("nike");
    cout << st.AverageShoePrice() << endl;
    */
    ShoeStore store;

    store.AddShoes("adidas", 20, 5);
    store.AddShoes("jordan", 100, 2);
    store.AddShoes("puma", 25, 4);
    store.AddShoes("nike", 125, 3);
    cout << store.AverageShoePrice() << endl;
    cout << store.getDiscountPrecent() << endl;
    store.SetDiscountPrecent(20);
    cout << store.AverageShoePrice() << endl;
    cout << store.GetShoePrice("nik") << endl;
}