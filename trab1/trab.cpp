#include <stdio.h>
#include <string.h>
#include <GL/glut.h>
#include <string>
#include <cmath>
#define TAMANHO_ARQUIVO 11

using namespace std;

// int media=0;

// int hash1 (int chave){
// 	int h1 = (chave % TAMANHO_ARQUIVO);
// 	return h1;
// }
//
// int hash2 (int chave){
// 	int h2 = (chave / TAMANHO_ARQUIVO);
// 	if (h2 == 0)
// 		h2 = 1;
// 	return h2;
// }
//
// int hash3 (int chave, int i){
// 	int h3 = ((hash1(chave) + i * hash2(chave)) % TAMANHO_ARQUIVO);
// 	return h3;
// }
//
// void insert(Noarchive f){
// 	int i, chave, idade, j;
// 	char nome[21];
// 	FILE *fh;
// 	int cont=0;
//
// 	scanf("%d",&chave);
// 	scanf ("\n\r%[^\n]",nome);
// 	scanf ("%d",&idade);
//
// 	i = 0;
// 	int h3 = hash3(chave, i);
//
// 	fh = fopen ("arquivo.bin", "rb+");
// 	rewind(fh);
// 	if (fh == NULL){
// 		return;
// 	}
//
// 	if (chave == -1)
// 		return;
//
// 	for (j=0; j<TAMANHO_ARQUIVO; j++){
// 		fseek(fh, (j * sizeof(struct Noarchive)), SEEK_SET);
// 		fread(&f, sizeof(struct Noarchive), 1, fh);
//
// 		if (f.key == chave){
// 			printf("chave ja existente: %d\n",chave);
// 			return;
// 		}
// 	}
//
// 	fseek(fh, (h3 * sizeof(struct Noarchive)), SEEK_SET);
// 	fread(&f, sizeof(struct Noarchive), 1, fh);
// 	fseek(fh, (h3 * (sizeof(Noarchive))), SEEK_SET);
// 	if (f.key == -1){
// 		f.key = chave;
// 		strcpy(f.name,nome);
// 		f.age = idade;
// 		fwrite(&f, sizeof(struct Noarchive), 1, fh);
// 		fclose(fh);
// 		return;
// 	}
//
// 	else{
// 		while (1){
// 			cont++;
// 			if (cont == TAMANHO_ARQUIVO)
// 				break;
// 			i++;
// 			h3 = hash3(chave, i);
// 			fseek(fh, (h3 * sizeof(struct Noarchive)), SEEK_SET);
// 			fread(&f, sizeof(struct Noarchive), 1, fh);
// 			fseek(fh, (h3 * (sizeof(Noarchive))), SEEK_SET);
// 			if (f.key == -1){
// 				f.key = chave;
// 				strcpy(f.name,nome);
// 				f.age = idade;
// 				fwrite(&f, sizeof(struct Noarchive), 1, fh);
// 				break;
// 			}
// 		}
// 	}
// 	fclose(fh);
// }
//
// void search(Noarchive f, int chave){
// 	FILE *fh;
// 	int j;
//
// 	fh = fopen ("arquivo.bin", "rb");
// 	rewind(fh);
// 	if (fh == NULL)
// 		return;
//
// 	if (chave == -1)
// 		return;
//
// 	for (j=0; j<TAMANHO_ARQUIVO; j++){
// 		fseek(fh, (j * sizeof(struct Noarchive)), SEEK_SET);
// 		fread(&f, sizeof(struct Noarchive), 1, fh);
//
// 		if (f.key == chave){
// 			printf("chave: %d\n",chave);
// 			printf("%s\n", f.name);
// 			printf("%d\n", f.age);
// 			return;
// 		}
// 	}
// 	printf("chave nao encontrada: %d\n",chave);
// 	fclose(fh);
// }
//
// void remove_key(Noarchive f, int chave){
// 	FILE *fh;
// 	int j;
//
// 	fh = fopen ("arquivo.bin", "rb+");
// 	rewind(fh);
// 	if (fh == NULL)
// 		return;
//
// 	if (chave == -1)
// 		return;
//
// 	for (j = 0; j < TAMANHO_ARQUIVO; j++){
// 		fseek(fh, (j * sizeof(struct Noarchive)), SEEK_SET);
// 		fread(&f, sizeof(struct Noarchive), 1, fh);
// 		fseek(fh, (j * sizeof(struct Noarchive)), SEEK_SET);
//
// 		if (f.key == chave){
// 			f.key = -1;
// 			fseek(fh, (j * sizeof(struct Noarchive)), SEEK_SET);
// 			fwrite(&f, sizeof(struct Noarchive), 1, fh);
// 			fclose(fh);
// 			return;
// 		}
// 	}
// 	printf("chave nao encontrada: %d\n",chave);
// 	fclose(fh);
// }
//
// void print_file(Noarchive f){
// 	FILE *fh;
// 	int i;
//
// 	fh = fopen("arquivo.bin", "rb");
// 	if (fh == NULL)
// 		return;
//
// 	rewind(fh);
// 	for (i = 0; i < TAMANHO_ARQUIVO; i++){
// 		fseek(fh, (i * (sizeof(Noarchive))), SEEK_SET);
// 		fread(&f, sizeof(struct Noarchive), 1, fh);
// 		fseek(fh, (i * (sizeof(Noarchive))), SEEK_SET);
// 		if (f.key == -1)
// 			printf("%d: vazio\n",i);
// 		else
// 			printf("%d: %d %s %d\n", i, f.key, f.name, f.age);
// 	}
// 	fclose(fh);
// }
//
// void individual_averange(Noarchive f, int chave){
// 	FILE *fh;
// 	int i=0;
// 	media = 0;
//
// 	int h3 = hash3(chave,i);
// 	fh = fopen("arquivo.bin","rb");
//
// 	if (fh == NULL)
// 		return;
//
// 	rewind(fh);
// 	fseek(fh, (h3 * sizeof(struct Noarchive)), SEEK_SET);
// 	fread(&f, sizeof(struct Noarchive), 1, fh);
// 	fseek(fh, (h3 * sizeof(struct Noarchive)), SEEK_SET);
//
// 	if (f.key == chave){
// 		media++;
// 		fclose(fh);
// 	}
// 	else {
// 		while(f.key != -1){
// 		i++;
// 		media++;
// 		h3 = hash3(chave,i);
//
// 		rewind(fh);
// 		fseek(fh, (h3 * sizeof(struct Noarchive)), SEEK_SET);
// 		fread(&f, sizeof(struct Noarchive), 1, fh);
// 		fseek(fh, (h3 * sizeof(struct Noarchive)), SEEK_SET);
//
// 		if(f.key == chave){
// 			media++;
// 			fclose(fh);
// 			return;
// 		}
// 	}}
// }
//
// float print_media(Noarchive f){
// 	FILE *fh;
// 	int i, j, soma=0;
// 	float cont;
//
// 	fh = fopen("arquivo.bin","rb");
//
// 	if (fh == NULL)
// 		return 1;
//
// 	for (i = 0; i < TAMANHO_ARQUIVO; i++){
// 		fseek(fh, (i * sizeof(struct Noarchive)), SEEK_SET);
// 		fread(&f, sizeof(struct Noarchive), 1, fh);
// 		fseek(fh, (i * sizeof(struct Noarchive)), SEEK_SET);
//
// 		if (f.key != -1){
// 			individual_averange(f, f.key);
// 			cont++;
// 			soma += media;
// 		}
// 	}
// 	fclose(fh);
// 	if (cont == 0)
// 		return 0.0;
// 	return soma / cont;
// }

void Model_PLY::Draw()
{
	glEnableClientState(GL_VERTEX_ARRAY);
 	glEnableClientState(GL_NORMAL_ARRAY);
	glVertexPointer(3,GL_FLOAT,	0,Faces_Triangles);
	glNormalPointer(GL_FLOAT, 0, Normals);
	glDrawArrays(GL_TRIANGLES, 0, TotalConnectedTriangles);
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
}

void inicializa (){
  glMatrixMode(GL_PROJECTION); // Define a janela de visualização
  glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0); // Define o sistema de coordenadas
  glViewport(0, 0, 640, 480);
  GLfloat aspect = (GLfloat) 640 / 480;
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(45, aspect, 1, 500);
  glMatrixMode(GL_MODELVIEW);
  glShadeModel( GL_SMOOTH );
  glClearColor(1.0, 1.0, 1.0, 1.0); // Define a cor de fundo da janela como azul
  glClearDepth(1.0);
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LEQUAL);
  glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void desenha(){

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Limpa a janela de visualização com a cor de fundo especificada
  glLoadIdentity(); // Substitui a matriz corrente por uma matriz identidade
  gluLookAt(0,4,4, 0,1,0, 0,6,0); // Define a posição da camera

  //glColor3f(1.0, 0.0, 0.0); // Define a cor de desenho como vermelho

  glPushMatrix();
  obj1.Draw();
  obj2.Draw();
  glPopMatrix();
  glutSwapBuffers();

  // Desenha um tri�ngulo
  // glBegin(GL_TRIANGLES);
  //   glVertex3f(0.5, 0.5, 0.0);
  //   glVertex3f(-0.5, 0.5, 0.0);
  //   glVertex3f(0.0, -0.5, 0.0);
  // glEnd();

  glFlush(); // Executa os comandos OpenGL para renderiza��o
}

int main(int argc, char** argv){

  glutInit(&argc, argv); // Inicia GLUT e processa argumentos passados por linha de comandos
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); // Avisa a GLUT que tipo de modo de exibi��o deve ser usado quando a janela é criada
  glutInitWindowSize(640, 480);	// Tamanho da janela
  glutCreateWindow("Olá Mundo!"); // Cria uma janela GLUT que permite a execu��o de comandos OpenGL
  glutDisplayFunc(desenha); // Define a fun��o respons�vel por redesenhar a janela OpenGL sempre que necess�rio
  glutIdleFunc(desenha);	// register Idle Function
  glutKeyboardFunc(teclado); // register Keyboard Handler
  Inicializa(); // Inicializa��es de OpenGL executadas antes da exibi��o do desenho

	obj1.Load(argv[1]);
	obj2.Load(argv[2]);

  // Inicia o processamento de eventos de GLUT. O controle do programa
  // passa a GLUT, que inicia o gerenciamento dos eventos
  glutMainLoop();

  return 0;
}
