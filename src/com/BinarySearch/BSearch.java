package com.BinarySearch;

import java.util.Arrays;

public class BSearch {
    public static void main(String[] args) {
        int[] arr = {2,4,6,7,9,11,12,15,18,20,25,28,29,30};
//        System.out.println(BinarySerach(arr,26));
        System.out.println(BinarySearchOA(arr,20));
    }
    public static int BinarySerach(int[] arr,int k){
        int s = 0;
        int e = arr.length-1;
        while(s<=e){
            int m = s+(e-s)/2;
            if(arr[m]==k)
                return m;
            else if(k>arr[m]){
                s=m+1;
            }else{
                e=m-1;
            }
        }
        return -1;
    }
    public static int BinarySearchOA(int[] arr,int k){
        int s=0;
        int e=arr.length-1;
        if(arr[s]<arr[e]){
            return BinarySerach(arr,k);
        }else{
            return BinarSearchDec(arr,k);
        }
    }
    public static int BinarSearchDec(int[] arr,int k){
        int s=0;
        int e=arr.length-1;
        while(s<=e){
            int m = s+(e-s)/2;
            if(arr[m]==k)
                return m;
            else if(k<arr[m])
                s=m-1;
            else
                e=m+1;
        }
        return -1;
    }
}
