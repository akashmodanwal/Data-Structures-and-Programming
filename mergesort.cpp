 // =============================================================
    // This is an implementation to question 2.3-2
    // =============================================================

    #include <iostream>
    #include <iomanip>
    
    using namespace std;
    
    // =============================================================
    
    void printArr(int[],const int);
    void mergeSort(int[],const int,const int);
    void merge(int[],const int,const int,const int);
    
    // =============================================================
    
    int main(){
        cout<<"============================================\n";
        cout<<"\t     :: Information ::\n";
        cout<<"This program  illustrates merge-sort without\n";
        cout<<"using sentinels.\n";
        cout<<"============================================\n";
        // =========================================================
        // Definitions and initialization
        int SIZE=8;
        // ---------------------------------------------------------
        int arr[8]={3,41,52,26,38,57,9,49};
        
        
        // =========================================================
        // Print the array before sorting:
        cout << "Before sorting:\n";
        printArr(arr,SIZE);
        cout<<"============================================\n";
        
        // =========================================================
        // Sorting:
        mergeSort(arr,0,SIZE-1);
        cout << "After sorting:\n";
        printArr(arr,SIZE);
        cout<<"============================================\n";
        
        return 0;
    }
    
    // =============================================================
    
    // =============================================================
    // This function would print the items of the array <arr>  whose
    // size is <SIZE>.
    void printArr(int arr[],const int SIZE){
        for(int i=0; i<SIZE; i++){
            cout << "Element " << setw(2) << i+1 << ": " << arr[i] 
                 << std::endl;
        }
    }

    // =============================================================
    
    // =============================================================
    // This  function  would  sort  the  array  <arr>  starting from 
    // <START_INDEX> to <END_INDEX>.
    void mergeSort(int arr[],const int START_INDEX,
                   const int END_INDEX){
        if( START_INDEX < END_INDEX){
            // -----------------------------------------------------
            // NOTE The type is int,  producing only integer values.
            // Get the integer mid index
            int midIndex = (START_INDEX + END_INDEX) / 2;
            
            // Sort the left subarray
            mergeSort(arr,START_INDEX, midIndex);
            
            // Sort the right subarray
            mergeSort(arr,midIndex+1,END_INDEX);
            
            // Merge the two sorted subarrays
            merge(arr,START_INDEX,midIndex,END_INDEX);
        }
    }
    
    // =============================================================
    
    // =============================================================
    // This function would merge the two subarrays  of <arr>;  where
    // one starts at index <START_INDEX> to <MID_INDEX>, and another
    // one starts at index <MID_INDEX> +1 to <END_INDEX>
    void merge(int arr[],const int START_INDEX, const int MID_INDEX,
               const int END_INDEX){
        // Get the size of the first array
        const int SIZE_1 = MID_INDEX - START_INDEX +1;
        // Get the size of the second array
        const int SIZE_2 = END_INDEX - MID_INDEX;
        
        // Dynamically allocate the two arrays:
        int * leftArray = new int[SIZE_1];
        int * rightArray = new int[SIZE_2];
        
        // ---------------------------------------------------------
        // NOTE Indices starts from ZERO, 0, and up to SIZE-1. Also,
        //      we will not subtract 1, like in the  pseudo-code, as
        //      the counter  variable starts  from 0,  instead of 1.
        // ---------------------------------------------------------
        // initialize the two arrays:
        for(int i=0; i<SIZE_1;i++){
            leftArray[i] = arr[START_INDEX + i];
        }
        
        for(int i=0; i<SIZE_2;i++){
            rightArray[i] = arr[MID_INDEX + i + 1];
        }
        
        // The two indices of the two arrays.
        int index1 = 0;
        int index2 = 0;
        
        // ---------------------------------------------------------
        // Start merging the elements:
        // Loop over the original items
        // ---------------------------------------------------------
        // CAUTION: See the explanation at the detailed answer.
        // ---------------------------------------------------------
        for(int i=START_INDEX; i<=END_INDEX; i++){
            if( (index1 < SIZE_1) && 
                 ( (index2 >= SIZE_2) || 
                   (leftArray[index1] <= rightArray[index2])
                 ) ){
                // Copy from the left array
                arr[i] = leftArray[index1];
                index1++;
            }else{
                arr[i] = rightArray[index2];
                index2++;
            }
        }
        
        // Release the allocated space
        delete[] leftArray;
        delete[] rightArray;
    }
    
    // =============================================================
