#include "listaposts.h"

/**
\struct Definição de listas ligadas de ids de posts
@param id_post Identificador do post
*/
struct lligada {
	long id_post;
  struct lligada *prox;
};

/**
\struct Estrutura com o identificador do utilizador e a lista dos seus posts
@param id_user Identificador do utilizador
@param lposts Lista com os posts do utilizador
*/
struct lposts {
	long id_user;
	Lista lposts;
};

/**
\struct Estrutura com o array que contém em cada índice o identificador do utilizador e os seus respetivos posts
@param size Tamanho do array
@param aposts Array com o identificador do utilizador e os seus respetivos posts
*/
struct arraypost{
	int size;
	int ocupados;
	PostsUsers * aposts;
};

/**
\brief Função que cria uma lista
@param post Identificador do post
@returns A lista com o id
*/
Lista createLista (long post){
  Lista l = malloc(sizeof (struct lligada));
	l->id_post = post;
  l->prox = NULL;
	return l;
}

/**
\brief Função que adiciona um id à cabeça da lista
@param l Lista com Identificador do post
@param id_post Identificador do post
@returns A lista com o id adicionado
*/
Lista addPost (Lista l, long post){
  Lista novo = createLista(post);
  novo->prox = l;

	return novo;
}

/**
\brief Função que calcula o tamanho de uma lista
@param l Lista
@returns O tamanho da lista
*/
int lengthL(Lista l){
  int tam = 0;
  while(l){
    tam++;
    l = l->prox;
  }
  return tam;
}

/**
\brief Função que cria uma célula com o identificador de um utilizador e uma lista com os seus posts
@param user Identificador do utilizador
@param l Lista dos posts
@returns A lista dos posts associados ao utilizador a que pertencem
*/
PostsUsers createPostsUsers (long user, Lista l){
  PostsUsers p = malloc(sizeof(struct lposts));
	p->id_user = user;
  p->lposts = malloc(sizeof(struct lligada));
	p->lposts = l;
	return p;
}
/**
\brief Função que cria um array de PostsUsers
@param size Tamanho do array
@returns O array de PostsUsers
*/
ArrayPosts createArrayPosts(int size){
	if (size <= 0) return NULL;
	ArrayPosts p = malloc(sizeof(struct arraypost));
	p->size = size;
	p->ocupados = 0;
	p->aposts = malloc(sizeof(struct lposts) * size);
    for(int i = 0; i < size; i++){
        p->aposts[i] = malloc(sizeof(struct lposts));
				p->aposts[i]->lposts = NULL;
    }
	return p;
}

/**
\brief Função que busca o identificador do post
@param l Lista dos identificadores de posts
@returns O id do post
*/
long getPostId_L(Lista l){
  return l->id_post;
}

/**
\brief Função que busca o identificador do utilizador
@param p PostsUsers
@returns O identificador do utilizador no PostsUsers p
*/
long getUserID_L (PostsUsers p){
  return p->id_user;
}

/**
\brief Função que busca a lista dos posts de um utilizador
@param p Array de posts
@param i Índice do array
@returns A lista dos posts que está no índice i
*/
Lista getListaPosts (ArrayPosts p, int i){
	return p->aposts[i]->lposts;
}

/**
\brief Função que busca o tamanho do array
@param p Array de posts
@returns Tamanho do array
*/
int getSizeArray (ArrayPosts p){
	 return p->size;
}

/**
\brief Função que busca o número de índices ocupados do array
@param p Array de posts
@returns O número de índices ocupados
*/
int getOcupados(ArrayPosts p){
	return p->ocupados;
}

/**
\brief Função que atualiza o número de índices ocupados do array
@param p Array de posts
@param o Número de ocupados atualizado
*/
void setOcupados(ArrayPosts p, int o){
	p->ocupados = o;
}

/**
\brief Função que busca o conteúdo num certo índice do array
@param p Array de posts
@returns Conteúdo do array na posição i
*/
PostsUsers getAPosts (ArrayPosts p, int i){
	return p->aposts[i];
}

/**
\brief Função que atualiza o PostsUsers da posição i do array
@param p Array de posts
@param i Índice do array
@param c PostsUsers atualizado
*/
void setAPosts(ArrayPosts p, int i, PostsUsers c){
	p->aposts[i] = c;
}

/**
\brief Função que liberta a lista dos posts de cada utilizador
@param p Posts de cada utilizador associado ao seu identificador
*/
void freePostsUsers (PostsUsers p){
	if(p->lposts != NULL)
				free(p->lposts);
	free(p);
}

/**
\brief Função que liberta o array de listas dos posts de cada utilizador
@param p Array de listas
*/
void freeArrayPosts (ArrayPosts p){
  for(int i = 0; i < p->size; i++)
		freePostsUsers(getAPosts(p,i));
}

/**
\brief Função que insere o identificador de um post na lista de posts de um certo utilizador
@param p Array de listas
@param user Identificador do utilizador
@param post Identificador do post
*/
void insere(Posts_D posts, ArrayPosts p){
  int i = 0;
  long user = getUserId(posts);
  long post = getPostId(posts);
  int ocup = getOcupados(p);

  if(getSizeArray(p) == 0)
      return;
  if  (ocup == 0){
      Lista pp = createLista(post);
      PostsUsers new = createPostsUsers(user, pp);
      ocup++;
      setOcupados(p,ocup);

       setAPosts(p, 0, new);

  }
  while (getUserID_L(getAPosts(p, i)) < user && getUserID_L(getAPosts(p, i)) != 0) i++;
    if(getUserID_L(getAPosts(p, i)) == user){
      Lista l = getListaPosts(p, i);
      if(l == NULL)
        createLista(post);
      else addPost(l, post);
    }
    else{
      int pos = i;

      for(int j = ocup; j > i; j--){
        PostsUsers anterior = getAPosts(p, j-1);
        setAPosts(p, j, anterior);
        }
      Lista l = createLista(post);
      PostsUsers novo = createPostsUsers(user, l);
      setAPosts(p, pos, novo);
      ocup++;
      setOcupados(p, ocup);
      }
}

/**
\brief Função que clona uma lista
@param l Lista a clonar
@returns A lista clonada
*/
Lista cloneLista (Lista l){
	Lista a = malloc(sizeof(struct lligada));
	a->id_post = l->id_post;
	a->prox = l->prox;
	return a;
}

/**
\brief Função que clona a estrutura dos PostsUsers
@param l PostsUsers a clonar
@returns A estrutura clonada dos PostsUsers
*/
PostsUsers clonePostUsers(PostsUsers l){
	PostsUsers a = malloc(sizeof(struct lposts));
	a->id_user = l->id_user;
	a->lposts = l->lposts;
	return a;
}

/**
\brief Função que clona a estrutura do ArrayPosts
@param l ArrayPosts a clonar
@returns A estrutura clonada do ArrayPosts
*/
ArrayPosts cloneArrayPosts(ArrayPosts l){
	ArrayPosts a = malloc(sizeof(struct arraypost));
	int i;
	a->size = l->size;
	a->ocupados = l->ocupados;
	for(i=0;i<l->size;i++){
	a->aposts[i] = l->aposts[i];
}
return a;
}

/**
\brief Função que busca o resto da lista
@param l Lista
@returns A lista l sem a cabeça
*/
Lista getProx(Lista l){
    return l->prox;
}

/**
\brief Função que liberta a lista
@param l Lista
*/
void freeLista(Lista l){
	free(l->prox);
	free(l);
}
/**
\brief Função que vê se um id de um post existe numa lista
@param l Lista
@param p id do post
@returns 1 se o id pertence à lista, 0 caso contrário
*/
int pertence(Lista l, long p){
	while(l != NULL){
		if(getPostId_L(l) == p)
			return 1;
		else l = getProx(l);
	}
	return 0;
}
