#include <iostream>
#include <unistd.h>

const int X_SIZE = 60;
const int Y_SIZE = 60;
bool masterGrid [Y_SIZE][X_SIZE];

bool checkCell(int x, int y) {
  int neighbors = 0;
  if( masterGrid[y][x] == true) {
    int xCheck[] = {x - 1, x + 1, x};
    int yCheck[] = {y - 1, y + 1, y};
    if( xCheck[0] < 0 ) {
      xCheck[0] = X_SIZE - 1;
    } else if( xCheck[1] >= X_SIZE ) {
      xCheck[1] = 0;
    }
    if( yCheck[0] < 0 ) {
      yCheck[0] = Y_SIZE - 1;
    } else if( yCheck[1] >= Y_SIZE ) {
      yCheck[1] = 0;
    }
    for(int a = 0; a < 3; a++) {
      for(int b = 0; b < 3; b++) {
        if( xCheck[a] != x || yCheck[b] != y) {
          if( masterGrid[yCheck[b]][xCheck[a]] ) {
            neighbors++;
          }
        }
      }
    }
    if( neighbors < 2 ) {
      return false;
    } else if( neighbors > 3 ) {
      return false;
    } else {
      return true;
    }
  } else {
    int xCheck[] = {x - 1, x + 1, x};
    int yCheck[] = {y - 1, y + 1, y};
    if( xCheck[0] < 0 ) {
      xCheck[0] = X_SIZE - 1;
    } else if( xCheck[1] >= X_SIZE ) {
      xCheck[1] = 0;
    }
    if( yCheck[0] < 0 ) {
      yCheck[0] = Y_SIZE - 1;
    } else if( yCheck[1] >= Y_SIZE ) {
      yCheck[1] = 0;
    }
    for(int a = 0; a < 3; a++) {
      for(int b = 0; b < 3; b++) {
        if( xCheck[a] != x || yCheck[b] != y) {
          if( masterGrid[yCheck[b]][xCheck[a]] ) {
            neighbors++;
          }
        }
      }
    }
    if( neighbors == 3 ) {
      return true;
    } else {
      return false;
    }
  }
}

void showGrid() {
  for( int a = 0; a < Y_SIZE; a++) {
    for(int b = 0; b < X_SIZE; b++) {
      if( masterGrid[a][b] ) {
        printf("o");
      } else {
        printf(".");
      }
      printf(" ");
    }
    printf("\n");
  }
  printf("\n");
}

int main() {
  for( int a = 0; a < Y_SIZE; a++) {
    for( int b = 0; b < X_SIZE; b++) {
      masterGrid[a][b] = false;
    }
  }
  int depth = 4;
  //Glider
  masterGrid [depth+0][depth+2] = true;
  masterGrid [depth+1][depth+0] = true;
  masterGrid [depth+1][depth+2] = true;
  masterGrid [depth+2][depth+1] = true;
  masterGrid [depth+2][depth+2] = true;
  /*
  //Traffic light
  masterGrid[depth+0][depth+0] = true;
  masterGrid[depth+1][depth+0] = true;
  masterGrid[depth+2][depth+0] = true;
  */
  while( true ) {
    showGrid();
    bool bufferGrid[Y_SIZE][X_SIZE];
    for( int a = 0; a < Y_SIZE; a++) {
      for( int b = 0; b < X_SIZE; b++) {
        if( checkCell(b, a) ) {
          bufferGrid[a][b] = true;
        } else {
          bufferGrid[a][b] = false;
        }
      }
    }
    for( int a = 0; a < Y_SIZE; a++ ) {
      for( int b = 0; b < X_SIZE; b++ ) {
        masterGrid[a][b] = bufferGrid[a][b];
      }
    }
    usleep(200000);
  }
      return 0;
}
