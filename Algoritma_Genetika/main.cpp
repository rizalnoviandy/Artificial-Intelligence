#include<stdio.h> //to use the printf function
#include<conio.h> //to use the getche function
#include<stdlib.h> //to use the rand function
#include<time.h>

typedef struct Chrom // creating the chrom structure
    {
    short int bit[12] ;
    float fit;
    }chrom; // now we have a chrom type that we can use
void *evpop(chrom popcurrent[4] ) ; //defining the functions that we will use
//int x(chrom popcurrent) ;
float y(chrom popcurrent) ;
void *pickchroms(chrom popcurrent[4] ) ;
void *crossover(chrom popnext[4] ) ;
void *mutation(chrom popnext[4] ) ;


int main() // the main function
{
    int num; // num is the no. of iterations
    int i, j;
    srand(time(0));
    printf("\nAlgoritma Genetika ini akan digunakan untuk menghitung optimasi luas 3 bagian pada bangunan rumah(Depan, Tengah, Belakang) dengan memenuhi rumus 3D+T+2B=35. Satuan meterpersegi\n") ; // introduction to the program
    enter: printf("\nMasukkan jumlah iterasi: ") ;
    scanf("%d", &num) ; // enter the no. of iterations in num

    chrom popcurrent[4] ; // we make 4 chromes of popcurrent
    chrom popnext[4] ; // we make 4 chromes of popnext

    if(num<1) // if a ‐ve number is inserted . . enter num again
    goto enter;
    
    evpop(popcurrent) ; //initialise pop current
    
    for(i=0; i<num; i++) // loop num times
    {
        printf("\nIterasi ke= %d\n", i) ; // print the iteration number
        
        for(j=0; j<4; j++)
            popnext[j] =popcurrent[j] ; //copy popcurrent to popnext in order to adjust it
            
        pickchroms(popnext) ; //pick best chromes
        crossover(popnext) ; //cross over to get children chromes
        mutation(popnext) ; //mutate with a low probability
        
        
        for(j=0; j<4; j++)
            popcurrent[j] =popnext[j] ; //copy the chromes of popnext to popcurrent
        if(popcurrent[3] . fit==0){
            break;
        }
    } 
    
    // loop back until no. of iterations is exceeded
    
    /*if(popnext[j] . fit == 50){
        printf()
        break;
    }*/
    //flushall(); // flush the input buffer
    //getche() ; // wait for a character from the keyboard to end
return 0;
} //end of main


void *evpop(chrom popcurrent[4] ) //takes a pointer to a chrom of 4 elements
{
    int i, j;
    int random;
    float P[4], totfit;
    for(j=0; j<4; j++) // loop of j to choose chromes from [0] to [3]
    {
        for(i=0; i<12; i++) // loop of i to choose the gen of the chrom from [0] to [11]
        {
            random=rand()%2 ; // make the random value o or 1 only
            popcurrent[j] . bit[i] =random; // initialising the bit[i] of chrom[j] with random
        } // end of for(i)
             
        popcurrent[j] . fit=y(popcurrent[j]) ; // calcualte the fitness of chrom[j]
     
        printf("\n popcurrent[%d] =%d%d%d%d %d%d%d%d %d%d%d%d fitness = %f", j,
        popcurrent[j] . bit[0] , popcurrent[j] . bit[1] , popcurrent[j] . bit[2] , popcurrent[j] . bit[3] ,
        popcurrent[j] . bit[4] , popcurrent[j] . bit[5] ,
        popcurrent[j] . bit[6] , popcurrent[j] . bit[7] , popcurrent[j] . bit[8] , popcurrent[j] . bit[9] ,
        popcurrent[j] . bit[10] , popcurrent[j] . bit[11] , popcurrent[j] . fit) ; // print the chrom[j]
                
    } // end of for(j)
        return(0) ;
} //end of evpop function


/*int x(chrom popcurrent) //x function that evaluate the value of a given chrom
{
    int b,t,d;
    b=(popcurrent.bit[0]*1)+(popcurrent.bit[1]*2)+(popcurrent.bit[2]*4)+(popcurrent.bit[3]*8)+(popcurrent.bit[4]*16) ;
    t=(popcurrent.bit[4]*1)+(popcurrent.bit[5]*2)+(popcurrent.bit[6]*4)+(popcurrent.bit[7]*8)+(popcurrent.bit[8]*16) ;
    d=(popcurrent.bit[9]*1)+(popcurrent.bit[10]*2)+(popcurrent.bit[11]*4)+(popcurrent.bit[12]*8)+(popcurrent.bit[13]*16) ;
    //if(popcurrent.bit[5]==1)
    //z=(1)*z; // z=sum of the ( bits * their weights) with the sign value
    //return(z) ; //return the value of z
} // end x function*/


float y(chrom popcurrent) // the y function that we look for it's maximum value takes x value
{
    float y,fung,b,t,d,a;
    d=(popcurrent.bit[0]*8)+(popcurrent.bit[1]*4)+(popcurrent.bit[2]*2)+(popcurrent.bit[3]*1);
    t=(popcurrent.bit[4]*8)+(popcurrent.bit[5]*4)+(popcurrent.bit[6]*2)+(popcurrent.bit[7]*1);
    b=(popcurrent.bit[8]*8)+(popcurrent.bit[9]*4)+(popcurrent.bit[10]*2)+(popcurrent.bit[11]*1);
    fung=((3*d)+t+(2*b)-35); // the function 
    y=1/fung;
    return(y);
} // end of y function

void *pickchroms(chrom popcurrent[4]) // pickchroms takes a pointer to array of chroms
{
    int i, j;
    chrom temp; //temp chrome to use in sorting
 
    for(i=0; i<3; i++) //sorting the given set due to fitness
        for(j=0; j<3; j++)
        {
            if(popcurrent[j+1] . fit>popcurrent[j] . fit)
            {
                temp=popcurrent[j+1] ;
                popcurrent[j+1] =popcurrent[j] ;
                popcurrent[j] =temp;
            } // end of if
        } // end of for loop
        
    for(i=0; i<4; i++)
        printf("\nSorting: popnext[%d] fitness=%f", i, popcurrent[i] . fit) ; //printing the result
    printf("\n") ; //print new line

    return(0) ;
} //end of pick chromes function


void *crossover(chrom popnext[ 4] ) // crossover function takes a pointer to array of chromes
{
    int random;
    int i;
    random=rand() ; //random cross over point
    random=((random%11)+1) ; // cross point should be between (1 ‐ 11)
    printf("Nilai random cross : %d",random);

    for(i=0; i<random; i++) //crossing the bits below the cross point index
    {
        popnext[ 2] . bit[ i] =popnext[ 0] . bit[ i] ; //child 1 cross over
        popnext[ 3] . bit[ i] =popnext[ 1] . bit[ i] ; // child 2 cross over
    } // end of for

    for(i=random; i<12; i++) // crossing the bits beyond the cross point index
    {
        popnext[ 2] . bit[ i] =popnext[ 1] . bit[ i] ; // child 1 cross over
        popnext[ 3] . bit[ i] =popnext[ 0] . bit[ i] ; // chlid 2 cross over
    } // end of for
    i=0;
    for(i=0; i<4; i++)
        popnext[i] . fit=y(popnext[i]) ; // calculating the fitness values for the new set !!!!!!!!!
    for(i=0; i<4; i++)
        printf("\nCrossOver popnext[%d] =%d%d%d%d %d%d%d%d %d%d%d%d fitness = %f", 
        i, popnext[ i] . bit[11] , popnext[ i] . bit[10] , popnext[ i] . bit[9] , popnext[ i] . bit[8] ,
        popnext[ i] . bit[7] , popnext[ i] . bit[6] , popnext[ i] . bit[ 5] , popnext[ i] . bit[ 4] , 
        popnext[ i] . bit[ 3] , popnext[ i] . bit[ 2] ,popnext[ i] . bit[1] , popnext[i] . bit[0] , 
        popnext[i] . fit) ; // printing the bits, value and fitness for the chromes of the new set

    return(0) ;
} // end crossover function


void *mutation(chrom popnext[4] ) // mutation funtion given a pointer to array of chromes
{
    int random;
    int row, col;
    random=rand()%100; //random value is between ( 0 ‐ 49 )
    
    if (random<=25) // Suppusiong Probability of mutation is 25 %
    {
        col=rand() %12; // random column (gene) choosing
        row=rand() %4; // random row ( chrome ) choosing
        
        if (popnext[ row] . bit[ col] ==0) // invert the bit to 1 if it was 0
            popnext[ row] . bit[ col] =1 ;
        else if (popnext[ row] . bit[ col] ==1) // invert the bit to 0 if it was 1
            popnext[ row] . bit[ col] =0;
            
        popnext[row] . fit=y(popnext[ row]) ; // calculate the fitness for the mutated chrome
        printf("\nMutation occured in popnext[%d] bit[%d] =%d%d%d%d %d%d%d%d %d%d%d%d fitness=%f", row, col, 
        popnext[ row] . bit[ 11] , popnext[ row] . bit[ 10] , popnext[ row] . bit[ 9] , popnext[ row] . bit[ 8] , popnext[ row] . bit[ 7] , popnext[ row] . bit[ 6] ,
        popnext[ row] . bit[ 5] , popnext[ row] . bit[ 4] , popnext[ row] . bit[ 3] , popnext[ row] . bit[ 2] , popnext[ row] . bit[ 1] , popnext[ row] . bit[ 0] , popnext[ row] . fit) ; // print the chrome index, bits, value, fintness of the mutated chrome
        
    } // end of if
    return(0) ;
} //end of mutation