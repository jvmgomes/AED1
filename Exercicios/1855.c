//João Vitor Moreira Gomes RA:176536
#include <stdio.h>


int main(void){
    int M, N, i, j;
    int linha = 0, coluna = 0;

    char direc, resp;
    
    scanf("%d", &M);
    scanf("%d", &N);
    char mapa[N][M];

    for(i=0; i<N; i++){
        for(j=0; j<M; j++){
            scanf(" %c", &mapa[i][j]);
        }
    }

    if(mapa[0][0] == '>'){
        direc = '>';
        mapa[0][0] = 'x';
        coluna++;
        while(1){
            if(linha>=N || linha<0 || coluna>=M || coluna<0){
                resp = '!';
                break;
            }
            else if(mapa[linha][coluna] == '*'){
                resp = '*';
                break;
            }
            else if(mapa[linha][coluna] == 'x'){
				resp = '!';
				break;
			}
            else if(mapa[linha][coluna] == 'v'){
                direc = 'v';
                mapa[linha][coluna] = 'x';
                linha++;
            }
            else if(mapa[linha][coluna] == '^'){
                direc = '^';
                mapa[linha][coluna] = 'x';
                linha--;
            }
            else if(mapa[linha][coluna] == '>'){
				direc = '>';
				mapa[linha][coluna] = 'x';
				coluna++;
			}
			else if(mapa[linha][coluna] == '<'){
				direc = '<';
				mapa[linha][coluna] = 'x';
				coluna--;
			}
			else if(mapa[linha][coluna] == '.'){
				if(direc == 'v'){
					linha++;
				}
				else if(direc == '^'){
					linha--;
				}
				else if(direc == '>'){
					coluna++;
				}
				else if(direc == '<'){
					coluna--;
				}
            }
        }
        printf("%c\n", resp);
    }
    else if(mapa[0][0] == 'v'){
		direc = 'v';
        mapa[0][0] = 'x';
		linha++;
		while(1){
			if(linha>=N || linha<0 || coluna>=M || coluna<0){
				resp = '!';
				break;
			}
			else if(mapa[linha][coluna] == '*'){
				resp = '*';
				break;
			}
			else if(mapa[linha][coluna] == 'x'){
				resp = '!';
				break;
			}
			else if(mapa[linha][coluna] == 'v'){
				direc = 'v';
                mapa[linha][coluna] = 'x';
				linha++;
			}
			else if(mapa[linha][coluna] == '^'){
				direc = '^';
                mapa[linha][coluna] = 'x';
				linha--;
			}
			else if(mapa[linha][coluna] == '>'){
				direc = '>';
                mapa[linha][coluna] = 'x';
				coluna++;
			}
			else if(mapa[linha][coluna] == '<'){
				direc = '<';
                mapa[linha][coluna] = 'x';
				coluna--;
			}
			else if(mapa[linha][coluna] == '.'){
				if(direc == 'v'){
					linha++;
				}
				else if(direc == '^'){
					linha--;
				}
				else if(direc == '>'){
					coluna++;
				}
				else if(direc == '<'){
					coluna--;
				}
			}
		}
		printf("%c\n", resp);
	}
	
	else if(mapa[0][0] == '*'){
		printf("*\n");
	}
	
	else{
		printf("!\n");
	}
    return 0;
}
