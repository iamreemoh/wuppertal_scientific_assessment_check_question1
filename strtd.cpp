#include<iostream>
using namespace std;

int count=0, temp=0;
float sum=0, mean=0, Max=0; 

int main()
{
    int N;
    std::cout<<"Enter a value for the order of a square matrix\n";
    cin>>N;        //input for the order of the matrix
    int M[N][N],A[N][N], MT[N][N]; // 'M' is a square matrix of order N. Let MT be the transpose of matrix M, and defining another 2D array to store absolute values of the original matrix
    system("clear"); //clearing the screen

    for(int i=0;i<N;i++) // Taking the values for each element in the matrix
    {
        for(int j=0;j<N;j++)
        {
            std::cout<<"Type in the element values for row "<<i+1<<" and column "<<j+1<<", then hit Enter\n";
            cin>>M[i][j];
            system("clear");
        }
    }

    int option; //'option' is for the choice of quantity
    std::cout<<"Press a number corresponding to the quantity you want to find\n";
    std::cout<<"1....Trace\n";
    std::cout<<"2....Sum,mean and max\n";
    std::cout<<"3....Absolute Sum,Absolute mean and Absolute max\n";
    std::cout<<"4....A vector of size N x 1 containing the mean of each row\n";
    std::cout<<"5....A vector of size N x 1 containing the mean of each column\n";
    std::cout<<"6....A matrix containing the result of multiplying M with its transpose\n";
    cin>>option;
    system("clear");


    switch(option)
    {
    case 1:{ 
        for(int i=0,j=0;i<N,j<N;i++,j++)
            {
                count+=M[i][j];
            }
        std::cout<<"Trace of the matrix is: "<<count;
    }break;

    case 2:{
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                sum+=M[i][j];       //sum of all the entries
                
                if (i>0&&j>0)       
                {
                    if (M[i-1][j-1]<M[i][j])        //comparing the entries to find the maximum one
                    {
                        Max=M[i][j];
                    }
                    else
                    {
                        Max=M[i-1][j-1];
                    }
                }


            }
        }

        mean=sum/(N+N);                   // calculating average
        std::cout<<"sum, mean and maximum of all the entries are "<<sum<<", "<<mean<<" and "<<Max<<".";
    }break;
    case 3:{
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                if(M[i][j]<0)           // checking for a negative entry
                {
                    
                    for(int x= M[i][j];x<0;x++)
                        {
                            temp+=1;       // storing the magnitude of the entry into a temporary place
                        }
                    A[i][j]=temp;        // storing the positive value of the original matrix
                    sum+=temp;           // sum of the magnitude of all the negative entries
                    temp=0;              

                
                }
                else
                {
                    sum+=M[i][j];        // sum of all the magnitude of all the positive entries
                    A[i][j]=M[i][j];     // coping the entries from the original matrix
                }
                


            }
        }

        for(int i=0;i<N;i++)            // to find the maximum from the matrix containing the absolute values of the original matrix
        {
            for(int j=0;j<N;j++)
            {
                if (i>0&&j>0)       
                {
                    if (A[i-1][j-1]<A[i][j])        //comparing the entries to find the maximum one
                    {
                        Max=A[i][j];
                    }
                    else
                    {
                        Max=A[i-1][j-1];
                    }
                }
            }
        }
        mean=sum/(N+N);                   // calculating average
        std::cout<<"sum, mean and maximum of the absolute value of all the entries are "<<sum<<", "<<mean<<" and "<<Max<<".";
    }break;

    case 4:{
        std::cout<<"A vector of size Nx1 containing the mean of each row:\n";
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                sum+=M[i][j];
            }
            mean=sum/N;
            std::cout<<"| "<<mean<<" |"<<endl;
            sum=0;

        }
    } break;

    case 5:{
        std::cout<<"A vector of size Nx1 containing the mean of each column:\n";
        for(int j=0;j<N;j++)
        {
            for(int i=0;i<N;i++)
            {
                sum+=M[i][j];
            }
            mean=sum/N;
            std::cout<<"| "<<mean<<" |"<<endl;
            sum=0;
        }
    } break;

    case 6:{
        std::cout<<"A matrix of size NxN containing the result of multiplying M with its transpose:\n";
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                MT[j][i]=M[i][j];       //creating a transpose of the original matrix M
            }
        }

        for(int i=0;i<N;i++)
        {
            for(int h=0;h<N;h++)
            {
                for(int j=0;j<N;j++)
                {
                    sum+=M[i][j]*MT[j][h];
                }
                A[i][h]=sum;
                sum=0;
            }
        }
        
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                std::cout<<A[i][j]<<" ";
            }
            std::cout<<endl;
        }

    }break;
    default:
    cout<<"Selection invalid";
    break;

    }
    return 0;
}