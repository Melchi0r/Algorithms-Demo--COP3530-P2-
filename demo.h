//
// Created by Hiram on 12/4/2017.
//
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <ctime>
#include <time.h>
using namespace std;

#ifndef COP3530_P2_DEMO_H
#define COP3530_P2_DEMO_H

#endif //COP3530_P2_DEMO_H


class treeNode{

public:
    treeNode* leftchild;
    treeNode* rightchild;
    int numbercontained;

    treeNode(int num){
        numbercontained = num;
        leftchild = nullptr;
        rightchild = nullptr;

    }
    ~treeNode(){
        delete leftchild;
        delete rightchild;
    }






};

class objstore{

    public:

    double time;
    string name;
    vector<int>* sortedlist;

   objstore(string sortname, double time, vector<int>* sortedlist){

    this->time = time;
    this->sortedlist = sortedlist;
    this->name = sortname;

   };

    ~objstore(){
        delete sortedlist;


    }

    void printObj(){
       cout << " Name: " << this->name;
        cout << " Time: " << this->time;
        cout << " List: ";
        for (int i = 0; i < this->sortedlist->size(); i++){
            cout << this->sortedlist->at(i) << " ";
        }
        cout << endl;



    }

    bool operator <(objstore* rhs){

        return (this->time > rhs->time);

    }
    bool operator >(objstore* rhs){

        return (this->time > rhs->time);
    }


};

class sortingmenu{

    public:

    treeNode* root;

    int numselection;
    int size;

    double timestart;
    double timeend;
   vector<int> list;

    sortingmenu(){

        this->numbermenu();
        if(this->numselection != 3) {
            this->algorithmmenu();
        }
    }

    void numbermenu(){
        int tempint;
        cout << "please select an option by number" << endl;

        cout << "Would you like to make your own list or a random list? (Please use positive integers, not all algorithms are suitable for negative numbers and they are set up for integers)" << endl;

        cout << "1 randomlist" << endl;
        cout << "2 your own" << endl;
        cout << "3 EXIT" << endl;

        cin >> this->numselection;
        cin.ignore();
        if (this->numselection == 2) {

            cout << "Please type the length of your list" << endl;


            cin >> this->size;
            cin.ignore();



            for (int i = 0; i < this->size; i++){

                cin >> tempint;
                this->list.push_back(tempint);
                cin.ignore();
            }

            this->printlist(this->list);
            cout << endl;
        }
        else if(this->numselection == 1){

            this->size = 20;

            srand(time(0));

            for(int i = 0; i < this->size; i++){

                this->list.push_back(rand() % 1000 + 1);


            }

            this->printlist(this->list);
            cout << endl;

        }else if(this->numselection == 3){

            return;

        }else{
            cout << "Invalid Option please select again" << endl;

             this->numbermenu();
        }




    };

    void algorithmmenu(){
        vector<int>* tempvector = new vector<int>;

        tempvector->reserve(this->size);
        copy(this->list.begin(), this->list.end(), back_inserter(*tempvector));
        this->printlist(*tempvector);
        cout << endl;

        cout << "Please select an option by number" << endl;

    cout << "Which Algorithm would you like to use." << endl;


    cout << "Note that which each of these the listed timecomplexity is only the sort." << endl;
    cout << "Please keep in mind to add an extra O(e*n) to the complexity for printing out step by step" << endl;
    cout << "e is the number of steps and n is the length of the list. This may cause some change in the time it takes to sort." << endl;
    cout << endl;
        cout << "Also the O notation is showint the worst case timecomplexity not the average" << endl;
        cout << endl;
    cout << "1 Bubble Sort" << endl;
    cout << "2 Merge Sort" << endl;
    cout << "3 Unbalanced Tree" << endl;
    cout << "4 Bucket Sort" << endl;
    cout << "5 Radix Sort" << endl;
    cout << "6 Selection Sort" << endl;
    cout << "7 Quick Sort" << endl;
    cout << "8 Insert Sort" << endl;
    cout << "9 Heap Sort" << endl;
    cout << "10 Priority Queue" <<endl;
    cout << "11 All of them" << endl;
    cout << "12 EXIT" << endl;


        cout<< endl << endl << "NOTE: time is in milliseconds as such there may be some variations in time (1 sort run is not the same time as that sort run with the same list)" << endl << endl;

        cin >> this->numselection;
        cin.ignore();

        if(this->numselection == 1){
            cout << "BubbleSort" << endl;
            this->timestart = clock();
            this->BubbleSort(tempvector);
            this->timeend = clock();

            cout << "Time is " << this->timeend - timestart << " Time complexity for sorting is O(n^2) " << endl;
            printlist(*tempvector);

        }

        else if(this->numselection == 2){
            cout << "MergeSort" << endl;

            this->timestart = clock();
            this->MergeSort(tempvector, 0, this->size - 1);
            this->timeend = clock();

            cout << "Time is " << (timeend - timestart) << " Time complexity for sorting is O(nlog(n)) " << endl;
            printlist(*tempvector);


        }

        else if(this->numselection == 3){
            cout << "Unbalanced tree" << endl;

            this->timestart = clock();
            this->Tree(tempvector);
            this->timeend = clock();

            cout << "Time is " << (timeend - timestart) << " Time complexity for sorting is O(n^2)" << endl;
            printlist(*tempvector);



        }

        else if(this->numselection == 4){
            cout << "Bucket Sort" << endl;

            int tempmax = 0;
            for(int g = 0; g < this->size; g++){

                if(tempvector->at(g) > tempmax){

                    tempmax = tempvector->at(g);

                }
                cout << tempmax << endl;


            }

            this->timestart = clock();
            this->BucketSort(tempvector, tempmax);
            this->timeend = clock();

            cout << "Time is " << (this->timeend - this->timestart) << " Time complexity for sorting is O(n + k)" << endl;

            cout << "Note k is the number of buckets. Also O(n+k) is the average The actual timecomplexity depends on the sort used with this. In this case it is BubbleSort so" << endl;
            cout <<"the worst case time complexity is really O(n^2)" << endl;
            cout << "Also for sake of simplicity this bucket sort uses 3 buckets based off the highest number in your list" << endl;
            printlist(*tempvector);



        }

        else if(this->numselection == 5){
            cout << "RadixSort" << endl;

            int max= 0;
            int j = 0;

            for(int i = 0; i < this->size; i++){
                j = tempvector->at(i);

                if(j > max){

                    max = j;
                }


            }


            this->timestart = clock();
            this->RadixSort(tempvector, max);
            this->timeend = clock();

            cout << "Time is " << (timeend - timestart) << " Time complexity for sorting is O(kn) " << endl;

            cout << "Note k is the length of the largest number." << endl;
            printlist(*tempvector);

        }

        else if(this->numselection == 6){
            cout << "SelectionSort" << endl;

            this->timestart = clock();
            this->SelectionSort(tempvector);
            this->timeend = clock();

            cout << "Time is " << (timeend - timestart) << " Time complexity for sorting is O(n^2) " << endl;
            printlist(*tempvector);

        }

        else if (this->numselection == 7) {
            cout << "QuickSort" << endl;

            this->timestart = clock();
            this->QuickSort(tempvector , 0 ,this->size-1);
            this->timeend = clock();

            cout << "Time is " << (timeend - timestart) << " Time complexity for sorting is O(n^2) " << endl;
            printlist(*tempvector);



        }
        else if (this->numselection == 8){
            cout << "InsertSort" << endl;

            this->timestart = clock();
            this->InsertSort(tempvector);
            this->timeend = clock();

            cout << "Time is " << (timeend - timestart) << " Time complexity for sorting is O(n^2) " << endl;
            printlist(*tempvector);



        }

        else if (this->numselection == 9){
            cout << "HeapSort" << endl;

            this->timestart = clock();
            this->HeapSort(tempvector);
            this->timeend = clock();

            cout << "Time is " << (timeend - timestart) << " Time complexity for sorting is O(nlogn) " << endl;
            printlist(*tempvector);



        }
        else if (this->numselection == 10){
            cout << "PriorityQueue" << endl;

            this->timestart = clock();
            this->priorityqueue(tempvector);
            this->timeend = clock();

            cout << "Time is " << (timeend - timestart) << " Time complexity for sorting is O(log(n)) " << endl;
            printlist(*tempvector);



        }
        else if (this->numselection == 11){

            this->Allofthem(tempvector);

        }
        else if(this->numselection == 12){

            return;

        }else{
            cout << "Invalid Input, Please Select Again" << endl;

            this->algorithmmenu();
            return;

        }
        cout << endl;
        cout << endl;

        delete tempvector;
        cout << "Please select by number" << endl;

        cout<<"Would you like to use the same list again?" << endl;


        cout <<"1: Yes" << endl;

        cout << "2: No" << endl;

        cout << "Type any other number to exit" << endl;

        cin >> this->numselection;
        cin.ignore();

        if(this->numselection == 1){

            this->algorithmmenu();

            return;
        }
        else if (this->numselection == 2){
            this->list.clear();
            this->numbermenu();
            this->algorithmmenu();

            return;
        }else{
            return;
        }

    }

    void printlist(vector<int> plist){

            cout << "the list is" << endl;
            for (int i = 0; i < plist.size(); i++){
                cout << plist.at(i) << " ";
            }
            cout << endl;
            cout << endl;
            cout << endl;


    };


    void BubbleSort(vector<int>* list){
        vector<int>* olist = list;

        int tempint;
        for(int i = olist->size() - 1; i > 1; i--){

            for(int k = 0; k < i; k++){

                if (olist->at(k) > olist->at(k+1)){

                    tempint = olist->at(k);
                    olist->at(k) = olist->at(k+1);
                    olist->at(k+1) = tempint;

                    this->printlist(*olist);
                }




            }

        }
        return;
    }

    void MergeSort(vector<int>* list, int ind1, int ind2){
        vector<int>* olist = list;
        int mid = 0;

        if (ind1 < ind2){

            mid = (ind1 +ind2) / 2;

            this->MergeSort(olist, ind1, mid);
            this->MergeSort(olist, mid +1 , ind2);

            this->merge(olist, ind1, mid, ind2);

            this->printlist(*olist);


        }


    }

    void merge(vector<int>* list ,int ind1,int mid,int ind2 ){
        vector<int>* olist = list;
        int msize = ind2 - ind1 + 1;
        int mergep = 0;
        int lpos = ind1;
        int rpos = mid + 1;
        int* mergelist = new int[msize];

        while(lpos <= mid && rpos <= ind2){
            if(olist->at(lpos) < olist->at(rpos)){
                mergelist[mergep] = olist->at(lpos);
                ++lpos;


            }else{
                mergelist[mergep] = olist->at(rpos);
                ++rpos;


            }

            ++mergep;

        }


        while(lpos <= mid){
            mergelist[mergep] = olist->at(lpos);
            ++lpos;
            ++mergep;

        }



        while(rpos <= ind2){
            mergelist[mergep] = olist->at(rpos);
            ++rpos;
            ++mergep;
        }

        for(mergep = 0; mergep < msize; ++mergep){
            olist->at(ind1 + mergep) = mergelist[mergep];
        }

        delete mergelist;

    }

    void Tree(vector<int>* list ){
        vector<int>* olist = list;
        this->root = new treeNode(olist->at(0));

        for(int i = 1; i < this->size; i++){
            addtree(olist->at(i),this->root);
            traversalp(this->root);
            cout << endl;
        }

        olist->clear();
        traversalvec(olist,this->root);
        delete this->root;
        printlist(*olist);

    }
    void addtree(int numadded, treeNode* root){

        treeNode* tempptr = new treeNode(numadded);
        treeNode* currnode = root;


            if(numadded <= currnode->numbercontained){
                if(currnode->leftchild == nullptr){
                    currnode->leftchild = tempptr;
                    cout << "added" << endl;
                    return;
                }else{
                    currnode = currnode->leftchild;
                    this->addtree (numadded, currnode);
                }

            }else{

                if(currnode->rightchild == nullptr){
                    currnode->rightchild = tempptr;
                    cout << "added" << endl;
                    return;
                }else{

                    currnode = currnode->rightchild;
                    this->addtree (numadded,currnode);
                }




            }



    }
    void traversalp (treeNode* currnode){
        if(currnode == nullptr){
            return;
        }

        if(currnode->leftchild != nullptr){
            traversalp(currnode->leftchild);
        }
        cout << currnode->numbercontained << " ";

        if(currnode->rightchild != nullptr) {
            traversalp(currnode->rightchild);
        }
    }

    void traversalvec (vector<int>* olist, treeNode* currnode){

        if(currnode->leftchild != nullptr) {
            traversalvec(olist,currnode->leftchild);
        }
        olist->push_back(currnode->numbercontained);

        if(currnode->rightchild != nullptr){

            traversalvec(olist,currnode->rightchild);

        }

    }

    void BucketSort(vector<int>* olist , int max){
   vector<int>* tempvector1 = new vector<int>;
   vector<int>* tempvector2 = new vector<int>;
   vector<int>* tempvector3 = new vector<int>;

        for(int i = 0; i < this->size; i++) {
            if (olist->at(i) <= (max / 3)) {

                tempvector1->push_back(olist->at(i));

            } else {
                if (olist->at(i) <= ((max / 3) * 2)) {

                    tempvector2->push_back(olist->at(i));

                } else {

                    tempvector3->push_back(olist->at(i));

                }
            }
        }
            cout << "Sort Bucket1" << endl << endl;
            this->BubbleSort(tempvector1);
            printlist(*tempvector1);
            cout << "Sort Bucket2" << endl << endl;
            printlist(*tempvector2);
            this->BubbleSort(tempvector2);
            cout << "Sort Bucket3" << endl << endl;
            printlist(*tempvector3);
            this->BubbleSort(tempvector3);

        olist->clear();

         for(int j = 0; j < tempvector1->size(); j++){

             olist->push_back(tempvector1->at(j));

         }
        for(int k = 0; k < tempvector2->size(); k++){
            olist->push_back(tempvector2->at(k));
        }
        for(int z = 0; z < tempvector3->size(); z++){

            olist->push_back(tempvector3->at(z));
        }

        tempvector1->clear();
        tempvector2->clear();
        tempvector3->clear();

        delete tempvector1;
        delete tempvector2;
        delete tempvector3;


    }

    void RadixSort(vector<int>* olist ,int max){

        for (int i=1; max/i >0 ; i *= 10){

            count(olist, i);
        }


    }
    void count(vector<int>*olist, int cd){
        vector<int> vector1;
        vector<int> vector2;
        for(int i = 0; i < olist->size(); i++){

            vector1.push_back(0);

        }

        for (int i = 0; i < 10; i++ ){

            vector2.push_back(0);
        }
        int tempint;

        for(tempint = 0; tempint < olist->size(); tempint++){
            vector2.at((olist->at(tempint)/cd) % 10)++;
        }

        for(tempint = 1; tempint < 10; tempint++){

            vector2.at(tempint) += vector2.at(tempint-1);
        }

        for(tempint = olist->size() -1; tempint>=0; tempint--){
            vector1.at(vector2.at((olist->at(tempint)/cd)%10)-1) = olist->at(tempint);
            vector2.at((olist->at(tempint)/cd)%10)--;
        }


        for(tempint = 0; tempint < olist->size();tempint++){

            olist->at(tempint) = vector1.at(tempint);


        }
        printlist(*olist);
        };
    void SelectionSort(vector<int>* olist){

        int min;
        int tempint;

        for (int i = 0; i < this->size; i++){

            int min = i;

            for(int j = i; j < this->size; j++){

                if(olist->at(min) > olist->at(j)){

                    min = j;


                }



            }

            tempint = olist->at(min);
            olist->at(min) = olist->at(i);
            olist->at(i) = tempint;

            this->printlist(*olist);

        }

        return;
    }

    void QuickSort(vector<int>* olist, int ind1, int ind2){
        int tempint = 0;

        if (ind1 >= ind2){
            return;

        }else{

            tempint = parquick(olist, ind1, ind2);

            this->printlist(*olist);

            this->QuickSort(olist,ind1 , tempint);
            this->QuickSort(olist, tempint+1, ind2);

            return;
        }


    }

    int parquick(vector<int>* olist, int ind1, int ind2){
    int tempint1 =ind1;
     int tempint2 =ind2;
     int tempint3 = 0;

     int mid = ind1 + (ind2 - ind1) / 2;
     int piv = olist->at(mid);


    bool fin = false;

        while(fin == false){

            while(olist->at(tempint1) < piv){

                ++tempint1;


            }

            while (piv < olist->at(tempint2)){

                --tempint2;

            }

            if(tempint1 >= tempint2){
                fin = true;
            }else {

                    tempint3 = olist->at(tempint1);
                    olist->at(tempint1) = olist->at(tempint2);
                    olist->at(tempint2) = tempint3;

                ++tempint1;
                --tempint2;

            }

        }
        return tempint2;

    }


    void InsertSort (vector<int>* olist){
    int insert;

        int j;
        int i;

        for(i=1; i < this->size; i++){

            int j = i;

            int insert = olist->at(i);

            for(; j>0 && olist->at(j-1) > insert; j--){

                olist->at(j) = olist->at(j-1);

                this->printlist(*olist);
            }
            olist->at(j) = insert;

            this->printlist(*olist);
        }

        return;

    }

    void HeapSort (vector<int>* olist){
        int tempint1;
        int tempint2;


        Hbuild(olist);
        printlist(*olist);
        for(tempint1 = this->size -1; tempint1 >= 0; tempint1--){
            tempint2 = olist->at(0);
            olist->at(0) = olist->at(tempint1);
            olist->at(tempint1) = tempint2;

            Heap(olist, 0, tempint1);

            printlist(*olist);
        }


    }

    void Hbuild (vector<int>* olist){
        for(int temp = (this->size/2)-1 ; temp>=0; temp--){

            Heap(olist, temp, this->size);
        }

    }

    void Heap (vector<int>* olist,int ind1,int fin){
        int tempint1 = ind1;
        int tempint2 = 2*ind1 + 1;
        int tempint3 = 2*ind1 + 2;
        int swap = 0;
        if(tempint2 < fin && olist->at(tempint2) > olist->at(tempint1)){

            tempint1 = tempint2;
        }

        if(tempint3 < fin && olist->at(tempint3) > olist->at(tempint1)){

            tempint1 = tempint3;
        }

        if(tempint1 != ind1){
            swap = olist->at(ind1);
            olist->at(ind1) = olist->at(tempint1);
            olist->at(tempint1) = swap;

            Heap(olist, tempint1, fin);
        }

    }

    void priorityqueue (vector<int>* olist){

        priority_queue<int, vector<int>, greater<int>> temppq;
        vector<int> tempvec;
        for(int i = 0; i < this->size; i++){
            temppq.push(olist->at(i));
            while(!temppq.empty()){
                tempvec.push_back(temppq.top());
                temppq.pop();
            }
            printlist(tempvec);
            for(int j = 0; j < tempvec.size(); j++){
                temppq.push(tempvec.at(j));
            }
            tempvec.clear();
        }

        olist->clear();

        while(!temppq.empty()){
            olist->push_back(temppq.top());
            temppq.pop();
        }
        printlist(*olist);

    }

    void Allofthem (vector<int>* olist){


        vector<int>* tempvecbubble = new vector<int>;
        tempvecbubble->reserve(this->size);
        copy(this->list.begin(), this->list.end(), back_inserter(*tempvecbubble));

        vector<int>* tempvecmerge = new vector<int>;
        tempvecmerge->reserve(this->size);
        copy(this->list.begin(), this->list.end(), back_inserter(*tempvecmerge));

        vector<int>* tempvecut = new vector<int>;
        tempvecut->reserve(this->size);
        copy(this->list.begin(), this->list.end(), back_inserter(*tempvecut));

        vector<int>* tempvecbucket = new vector<int>;
        tempvecbucket->reserve(this->size);
        copy(this->list.begin(), this->list.end(), back_inserter(*tempvecbucket));

        vector<int>* tempvecrad = new vector<int>;
        tempvecrad->reserve(this->size);
        copy(this->list.begin(), this->list.end(), back_inserter(*tempvecrad));

        vector<int>*  tempvecselect = new vector<int>;
        tempvecselect->reserve(this->size);
        copy(this->list.begin(), this->list.end(), back_inserter(*tempvecselect));

        vector<int>* tempvecquick = new vector<int>;
        tempvecquick->reserve(this->size);
        copy(this->list.begin(), this->list.end(), back_inserter(*tempvecquick));

        vector<int>* tempvecins = new vector<int>;
        tempvecins->reserve(this->size);
        copy(this->list.begin(), this->list.end(), back_inserter(*tempvecins));

        vector<int>* tempvechp = new vector<int>;
        tempvechp->reserve(this->size);
        copy(this->list.begin(), this->list.end(), back_inserter(*tempvechp));

        vector<int>* tempvecpq = new vector<int>;
        tempvecpq->reserve(this->size);
        copy(this->list.begin(), this->list.end(), back_inserter(*tempvecpq));



        priority_queue<objstore*, vector<objstore*>, greater<objstore*>> rsort;


        int max = 0;
        for(int g = 0; g < this->size; g++){

            if(tempvecbucket->at(g) > max){
                max = tempvecbucket->at(g);
            }


        }

        cout << "BubbleSort: " << "O(n^2)" << endl;
        this->timestart = clock();
        BubbleSort(tempvecbubble);
        this->timeend = clock();
        rsort.push(new objstore("BubbleSort: O(n^2)", this->timeend - this->timestart, tempvecbubble));

        cout << endl;


        cout << "BucketSort: " << "O(n^2)" << endl;
        this->timestart = clock();
        BucketSort(tempvecbucket, max);
        this->timeend = clock();
        rsort.push(new objstore("BucketSort: O(n^2)", this->timeend- this->timestart, tempvecbucket));
        cout << endl;

        cout << "HeapSort: O(n logn)" << endl;
        this->timestart = clock();
        HeapSort(tempvechp);
        this->timeend = clock();
        rsort.push(new objstore("HeapSort: O(nlogn", this->timeend - this->timestart, tempvechp));
        cout << endl;

        cout << "Insertsort: O(n^2)" << endl;
        this->timestart = clock();
        InsertSort(tempvecins);
        this->timeend = clock();
        rsort.push((new objstore("Insertsort: O(n^2)", this->timeend - this->timestart, tempvecins)));
        cout << endl;


        cout << "MergeSort: O(nlogn)" << endl;
        this->timestart = clock();
        MergeSort(tempvecmerge,0,this->size - 1);
        this->timeend = clock();

        rsort.push(new objstore ("MergeSort: O(nlogn)", this->timeend - this->timestart, tempvecmerge));
        cout << endl;

        cout << "Priority queue: O(logn)" << endl;
        this->timestart = clock();
        priorityqueue(tempvecpq);
        this->timeend = clock();

        rsort.push(new objstore("Priority queue: O(logn)", this->timeend-this->timestart, tempvecpq));
        cout << endl;

        cout << "Quick sort: O(n^2)" << endl;
        this->timestart = clock();
        QuickSort(tempvecquick,0,this->size-1);
        this->timeend = clock();

        rsort.push(new objstore("Quicksort: O(n^2)", this->timeend - this->timestart, tempvecquick));
        cout << endl;

        cout<<"Radix Sort: O(nk)" << endl;
        this->timestart = clock();
        RadixSort(tempvecrad , max);
        this->timeend = clock();

        rsort.push(new objstore("Radixsort: O(nk)", this->timeend - this->timestart,tempvecrad ));
        cout << endl;


        cout <<"Selection Sort: O(n^2)" <<endl;
        this->timestart = clock();
        SelectionSort(tempvecselect);
        this->timeend = clock();

        rsort.push(new objstore("Selectionsort: O(n^2)", this->timeend - this->timestart, tempvecselect));
        cout << endl;

        cout <<"Unbalanced tree: O(n^2)" << endl;
        this->timestart = clock();
        Tree(tempvecut);
        this->timeend=clock();
        rsort.push(new objstore("Unbalanced tree: O(n^2)", this->timeend- this->timestart, tempvecut));

        objstore* tempptr;

        while(!rsort.empty()){

            tempptr = rsort.top();


            tempptr->printObj();
            rsort.pop();

            delete tempptr;

        }


    }



};
