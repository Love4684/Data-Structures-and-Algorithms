Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

![rainwatertrap](https://user-images.githubusercontent.com/42657629/95177014-46ae6a80-07db-11eb-8fe3-578ded353d25.png)

input : arr[]={1, 0, 2, 1, 0, 1, 1, 3, 2, 1, 2, 1}
output: 7
Method 1 : 

          hint : Crate new array for left max
                 
                 L[] = {1, 1, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3}
                 
                 Create another array for right max
                 
                 R[] = {3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 2, 1}
                 
                 water wil trap between minimum of right and left
                 min(L[i] , R[i]) - arr[i]
                 
                 
