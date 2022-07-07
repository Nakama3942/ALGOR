#include <iostream>
using std::cout;

#include "N:/ALGOR/src/ALGOR.hpp"
using namespace ALGOR;
using namespace ALGOR::SORTING;

template <typename type_array>
class printer : public Printer<type_array>
{
public:
    virtual ~printer(){};
    void setData(Array<type_array> **ARRAY)
    {
        Array = ARRAY;
    }
    void print() override
    {
        // cout.precision(25);
        for (asize_t i = 0; i < (*Array)->array_size; i++)
        {
            cout << " " << (*Array)->array[i];
        }
        cout << "\n";
    }

private:
    Array<type_array> **Array;
};

int main()
{
    Array<byte8_t> *D;
    printer<byte8_t> *pr = new printer<byte8_t>;
    pr->setData(&D);

    cout << "A:\n";
    ARRAYDATA<byte8_t> *A = new ARRAYDATA<byte8_t>(35);
    A->generatedData(10, 1000);
    D = A->getData();
    pr->print();
    cout << "\n";

    cout << "B:\n";
    ARRAYDATA<byte8_t> *B = new ARRAYDATA<byte8_t>(15);
    B->generatedData(10, 1000);
    D = B->getData();
    pr->print();
    cout << "\n";

    cout << "NEW A:\n";
    *A <<= B;
    D = A->getData();
    pr->print();
    cout << "\n";

    cout << "NEW B:\n";
    *B -= 2;
    D = B->getData();
    pr->print();
    cout << "\n";

    cout << "C:\n";
    ARRAYDATA<byte8_t> *C = new ARRAYDATA<byte8_t>(7);
    C->generatedData(10, 1000);
    D = C->getData();
    pr->print();
    cout << "\n";

    cout << "NEW C:\n";
    D = *A /= 3;
    *C = D;
    pr->print();
    cout << "\n";

    cout << "NEW SIZE B:\n";
    *B ^= 4;
    D = B->getData();
    pr->print();
    cout << "\n";

    cout << (*C == D) << "\n";
    D = A->getData();
    cout << (*C == D) << "\n";

    Array<asize_t> *X = A->getPosition(A->getValue(18));
    for (asize_t i = 0; i < X->array_size; i++)
    {
        cout << " " << X->array[i];
    }
    cout << "\n";
    remove_struct(X);

    cout << RANDOM::tester<RANDOM::LCM>(0, 999999) << "\n";
    cout << RANDOM::tester<RANDOM::MersenneTwister>(0, 999999) << "\n";

    cout << "W:\n";
    Array<byte8_t> *Y;
    printer<byte8_t> *pry = new printer<byte8_t>;
    pry->setData(&Y);
    ARRAYDATA<byte8_t> *W = new ARRAYDATA<byte8_t>(16);
    Y = W->getData();
    W->generatedData(14, 500);
    pry->print();
    Comparative_Sorts<byte8_t> *comp_int_sort = new Comparative_Sorts<byte8_t>(Y);
    comp_int_sort->Batcher_OddEven_MergeSort();
    pry->print();
    ArrayProcessing<byte8_t>::isOrderliness(Y->array, Y->array_size) ? cout << "Масив отсортовано\n" : cout << "Масив НЕ отсортовано\n";
    cout << "\n";
    W->generatedData(-140, 500);
    Y = W->getData();
    pry->print();
    comp_int_sort->Batcher_OddEven_MergeSort();
    pry->print();
    ArrayProcessing<byte8_t>::isOrderliness(Y->array, Y->array_size) ? cout << "Масив отсортовано\n" : cout << "Масив НЕ отсортовано\n";
    cout << "\n";
    W->generatedData(-140, -50);
    pry->print();
    comp_int_sort->Batcher_OddEven_MergeSort();
    pry->print();
    ArrayProcessing<byte8_t>::isOrderliness(Y->array, Y->array_size) ? cout << "Масив отсортовано\n" : cout << "Масив НЕ отсортовано\n";
    cout << "\n";
    delete (comp_int_sort);
    cout << "\n";

    cout << "K:\n";
    Array<fbit64_t> *M;
    printer<fbit64_t> *prf = new printer<fbit64_t>;
    prf->setData(&M);
    ARRAYDATA<fbit64_t> *K = new ARRAYDATA<fbit64_t>(16);
    M = K->getData();
    K->generatedData(14, 500, 100);
    prf->print();
    Comparative_Sorts<fbit64_t> *comp_float_sort = new Comparative_Sorts<fbit64_t>(M);
    comp_float_sort->Batcher_OddEven_MergeSort();
    prf->print();
    ArrayProcessing<fbit64_t>::isOrderliness(M->array, M->array_size) ? cout << "Масив отсортовано\n" : cout << "Масив НЕ отсортовано\n";
    cout << "\n";
    K->generatedData(-140, 500, 100);
    prf->print();
    comp_float_sort->Batcher_OddEven_MergeSort();
    prf->print();
    ArrayProcessing<fbit64_t>::isOrderliness(M->array, M->array_size) ? cout << "Масив отсортовано\n" : cout << "Масив НЕ отсортовано\n";
    cout << "\n";
    K->generatedData(-140, -50, 100);
    prf->print();
    comp_float_sort->Batcher_OddEven_MergeSort();
    prf->print();
    ArrayProcessing<fbit64_t>::isOrderliness(M->array, M->array_size) ? cout << "Масив отсортовано\n" : cout << "Масив НЕ отсортовано\n";
    cout << "\n";
    delete (comp_float_sort);
    cout << "\n";

    cout << "SORTED P:\n";
    Array<byte8_t> *R;
    printer<byte8_t> *prb = new printer<byte8_t>;
    prb->setData(&R);
    ARRAYDATA<byte8_t> *P = new ARRAYDATA<byte8_t>(8);
    R = P->getData();
    P->generatedData(11, 120);
    prb->print();
    Distribution_Sorts *dist_sort = new Distribution_Sorts(R);
    dist_sort->Pigeonhole_Sort();
    prb->print();
    ArrayProcessing<byte8_t>::isOrderliness(R->array, R->array_size) ? cout << "Масив отсортовано\n" : cout << "Масив НЕ отсортовано\n";
    cout << "\n";
    P->generatedData(-110, 120);
    prb->print();
    dist_sort->Pigeonhole_Sort();
    prb->print();
    ArrayProcessing<byte8_t>::isOrderliness(R->array, R->array_size) ? cout << "Масив отсортовано\n" : cout << "Масив НЕ отсортовано\n";
    cout << "\n";
    P->generatedData(-110, -12);
    prb->print();
    dist_sort->Pigeonhole_Sort();
    prb->print();
    ArrayProcessing<byte8_t>::isOrderliness(R->array, R->array_size) ? cout << "Масив отсортовано\n" : cout << "Масив НЕ отсортовано\n";
    cout << "\n";
    delete (dist_sort);
    cout << "\n";

    delete (prb);
    delete (prf);
    delete (pry);
    delete (pr);
    return 0;
}
