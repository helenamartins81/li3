#include "postsD.h"


/**
\struct Estrutura(AVL) que armazena os posts ordenados pela data de criação
@param data_post Data do post
@param id_user Identificador do utilizador
@param id_post Identificador do post
@param titulo  Título do post
@param num_respostas Número de respostas do post
@param post_type Tipo do post
@param parent_id Identificador do pai
@param num_comentarios Número de comentarios do post
@param score Score do post
@param tags Tags presentes no post
*/

struct Posts_data
{
	Data data_post;
	long id_user;
	long id_post;
	char* titulo;
	int num_respostas;
	int post_type;
	long parent_id;
	int num_comentarios;
	int score;
	Tags tags;
};

/**
\brief Função que cria uma estrutura dos posts
@param d Data do post
@param user Identificador do utilizador
@param post Identificador do post
@param title  Título do post
@param respostas Número de respostas do post
@param ptype Tipo do post
@param parent Identificador do pai
@param com Número de comentarios do post
@param score Score do post
@param t Tags presentes no post
@returns A estrutura dos posts
*/
Posts_D createPostsD (Data d, long user, long post, char* title,int respostas,
		int ptype, long parent, int com, int score, Tags t){
			Posts_D r = malloc(sizeof(struct Posts_data));
			r->data_post = d;
			r->id_user = user;
			r->id_post = post;
			r->titulo = mystrdup(title);
			r->num_respostas = respostas;
			r->post_type = ptype;
			r->parent_id = parent;
			r->num_comentarios = com;
			r->score = score;
			r->tags = t;
			return r;
	}



/**
\brief Função que busca a data do post
@param posts Estrutura dos posts
@returns A data do post
*/
Data getDate (Posts_D posts){
	return cloneData(posts->data_post);
}

/**
\brief Função que busca o identificador do utilizador
@param posts Estrutura dos posts
@returns O id do utilizador
*/
long getUserId (Posts_D posts){
	return posts->id_user;
}

/**
\brief Função que busca o identificador do post
@param posts Estrutura dos posts
@returns O id do post
*/
long getPostId (Posts_D posts){
	return posts->id_post;
}

/**
\brief Função que busca o título do post
@param posts Estrutura dos posts
@returns Apontador para o título do post
*/
char* getTitle (Posts_D posts){
	return mystrdup(posts->titulo);
}

/**
\brief Função que busca o número de resposta do post
@param posts Estrutura dos posts
@returns O número de respostas
*/
int getAnswers (Posts_D posts){
	return posts->num_respostas;
}

/**
\brief Função que busca o tipo de post
@param posts Estrutura dos posts
@returns O tipo de post
*/
int getPostType (Posts_D posts){
	return posts->post_type;
}

/**
\brief Função que busca o id do pai caso exista
@param posts Estrutura dos posts
@returns O id do pai
*/
long getParentId (Posts_D posts){
	return posts->parent_id;
}

/**
\brief Função que busca o número de comentarios
@param posts Estrutura dos posts
@returns O número de comentarios
*/
int getComments (Posts_D posts){
	return posts->num_comentarios;
}

/**
\brief Função que busca o score de um post
@param posts Estrutura dos posts
@returns O score do post
*/
int getScore (Posts_D posts){
	return posts->score;
}

/**
\brief Função que busca as Tags de um post
@param posts Estrutura dos posts
@returns Apontador para as Tags do post
*/
Tags getTags (Posts_D posts){
	return (cloneTags(posts -> tags));
}

/**
\brief Função que liberta a estrutura dos Posts_D
@param posts Estrutura dos posts
*/
void freePostsD (gpointer posts){
	 g_tree_destroy((GTree*)posts);
}

/**
\brief Função que clona a estrutura dos Posts_D
@param posts Estrutura dos Posts_D a clonar
@returns A estrutura clonada dos Posts_D
*/
Posts_D clonePostsD (Posts_D posts){
	Posts_D p = malloc(sizeof(struct Posts_data));
	p->data_post = posts -> data_post;
	p->id_user = posts->id_user;
	p->id_post = posts->id_post;
	p->titulo = posts->titulo;
	p->num_respostas = posts->num_respostas;
	p->post_type = posts->post_type;
	p->parent_id = posts->parent_id;
	p->num_comentarios = posts->num_comentarios;
	p->score = posts->score;
	p->tags = posts -> tags;
	return p;
}
/**
\brief Função de comparação de datas para criar a AVL
@param a Valor
@param b Valor a comparar
@returns 0 se forem iguais, 1 se a for maior que b e -1 caso contrário
*/
gint data_ord (gconstpointer a, gconstpointer b){
    Data a1 = (Data) a;
    Data a2 = (Data) b;
  return (compareMyData(a1, a2));
}
