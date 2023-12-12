#include <stdio.h>
#include <stdlib.h>






/*
char ch = 'A', mat[N][N] = {
{'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'}, 
{'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'}, 
{'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'}, 
{'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'}, 
{'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'}, 
{'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'}, 
{'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'}, 
{'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'}, 
{'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'}, 
{'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'}};  
*/

#define N 10
 

void doldur(char mat[N][N]) {
	int r;
	int c;
    for ( r = 0 ; r < N ; r++ ) {
        for ( c = 0 ; c < N ; c++ ) {
            mat[r][c] = '.';
        }
    }
}
 
void print(char mat[N][N]) {
	int r;
	int c;
    for ( r = 0 ; r < N ; r++ ) {
        for ( c = 0 ; c < N ; c++ ) {
            printf("%c ",mat[r][c]);
        }
        printf("\n");
    }
}
 
void pickMove(int *dx, int *dy) {
	/*rand kullandýðým yer*/
    int direction = rand() % 4;
    switch ( direction ) {
        case 0:
            *dx = 1; *dy = 0;
            break;
        case 1:
            *dx = -1; *dy = 0;
            break;
        case 2:
            *dx = 0; *dy = 1;
            break;
        case 3:
            *dx = 0; *dy = -1;
            break;
    }
}
 
int isValidMove(char mat[N][N], int row, int col, int dx, int dy) {
    int r = row + dx, c = col + dy;
    
    if ( r < 0 || r >= N ) return 0;
    if ( c < 0 || c >= N ) return 0;
    
    if ( mat[r][c] != '.' ) return 0;
    
    return 1;
}
/*100 
677741240
611911301
516687479
1039653884
807009856
115325623
1224653905
2083069270
1106860981
922406371
876420180
322411828
1259609597
1356425747
1318253490
883344301
229978180
1871801538
567764310
1334753943
1440409294
768869741
447440212
1147132415
825732306
1813670413
1897413451
991129617
1396963907
1658754524
1065898046
2074705148
123182177
1582585525
966875384
930192033
1697911148
44045642

bu cok basamakli sayilari nerede kullanacagiz?
*/
 
int main ( ) {
    char mat[N][N];
    char ch = 'A';
    int row = 0, col = 0;
    doldur(mat);
    mat[row][col] = ch;
    int the;
    scanf("%d",&the);
    srand(the);
    int tryagain = 0;
    int maxtries = 5;
    for ( ch = 'B' ; ch <= 'Z' ; ) {
        int dx, dy;
        pickMove(&dx,&dy);
        if ( isValidMove(mat,row,col,dx,dy) ) {
            row += dx;
            col += dy;
            mat[row][col] = ch++;
            tryagain = 0;
        } else if ( tryagain++ == maxtries ) {
            break;
        }
    }
    print(mat);
    return 0;
}
