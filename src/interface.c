#include "data.h"
#include "date.h"
#include "interface.h"
#include "list.h"
#include "listaposts.h"
#include "pair.h"
#include "parser.h"
#include "postsD.h"
#include "postsID.h"
#include "tags.h"
#include "user.h"
#include "users.h"

#include "string.h"
#include <glib.h>



/**
\struct Definição do tipo abstrato(TAD) da estrutura principal
@param postsbydata Estrutura dos posts ordenados pela data
@param postsbyid Estrutura dos posts ordenados pelo id
@param Users Estrutura dos utilizadores
*/
struct TCD_community {
  Posts_D postsbydata;
  Posts_ID postsbyid;
  Users users;
};


//TAD_community init();

//TAD_community load(TAD_community com, char* dump_path);

//q1
STR_pair info_from_post(TAD_community com, long id){
  STR_pair res;
  long id_pai;
  Posts_ID p = g_tree_lookup(com->postsbyid, id);
    if(getPostId2(p) == 1){
        Users u = g_hash_table_lookup(com->users, getUserId2(p));
        res = create_str_pair(getTitle2(p), getName(u));
      }
    else if(getPostId2(p) == 2){
        id_pai = getParentId2(p);
        p = g_tree_lookup(com->postsbyid, id_pai);
        Users u = g_hash_table_lookup(com->users, getUserId2(p));
        res = create_str_pair(getTitle2(p), getName(u));
    }
  return res;
}
/*
//q2

LONG_list top_most_active(TAD_community com, int N){

  g_tree_foreach(com->postsbydata, --, --)

}

//q3
LONG_pair total_posts(TAD_community com, Date begin, Date end){
    long respostas = 0;
    long perguntas = 0;

  gpointer *inicio = g_tree_lookup(com->postsbydata, begin);

  g_tree_foreach(inicio, (GTraverseFunc) compareData(inicio->data_post ,end),

}
*/

//Função que verifica se uma tag está numa lista de tags - aux p/ q4
int existeTag(char* tag, Tags t){

  if (!t) return 0;
  while(t != NULL){
    if(strcmp(tag, getNameTag(t)) == 0)
      return 1;
    else t = t->prox;
  }
  return 0;
}
/*
Lista func(Posts_D posts, char* tag, LONG_list l){
    int n = 0;
    Lista guarda = NULL;
    if(getPostType(posts) == 1){
      if(existeTag(tag, getTags(posts))){
        if(!guarda)
            guarda = createLista(getPostId(posts));
        else{
        guarda = addPost(guarda, getPostId(posts));
      }
      n++;
    }
  }
    l->size = n;
    return guarda;
}


//q4
LONG_list questions_with_tag(TAD_community com, char* tag, Date begin, Date end){
      gpointer *inicio = g_tree_lookup(com->postsbydata, begin);

      LONG_list res = create_list(0);
      g_tree_foreach(inicio, (GTraverseFunc) dataIgual(end, getDate(inicio)), *func(inicio, tag, res));

}
*/
//q5

USER get_user_info(TAD_community com, long id){
  USER res;
  Users u = g_hash_table_lookup(com->users, id);

  res->bio = getBio(u);
  //parte dos ultimos 10 posts

  return res;
}


//Função que ve se uma palavra pertence a uma string - usar a strstr -aux a q8
int pertenceTitulo(char* palavra, Posts_D p){

  if (strstr(getTitle(t), palavra) != NULL)
    return 1;
  return 0;
}

//q8

//LONG_list contains_word(TAD_community com, char* word, int N){



//}


//Funçao que calcula o valor da resposta para q10

int valResposta(TAD_community com, Posts_D p){
  int val;
  int rep, scr, vot, comt;

  scr = vot = getScore(p);
  comt = getComments(p);

  User u = g_hash_table_lookup(com->users, getUserId(p));
  rep = getRep(u);

  val = (scr * 0.45 + rep * 0.25 + vot * 0.2 + comt * 0.1);
  return val;
}

gboolean aux (Posts_D p, Date begin, long id){
  if((dataIgual(getDate(p), begin) > 0) && (getPostId(p) == 2)){
    if(getParentId(p) == id) return TRUE;
    }
  return FALSE;
}

//q10 erros no uso das funçoes do glib probably
long better_answer(TAD_community com, int id){
  int respostas;
  long melhor;
  int val;
  int maxval = 0;
  GTree *tree;

  Posts_ID post = g_tree_lookup(com->postsbyid, id);
  Data d = getDate2(post);
  Posts_D pergunta = g_tree_lookup(com->postsbydata, d));

  repostas = getAnswers(pergunta);

  while(respostas > 0){
    tree = pergunta;
    g_tree_foreach(tree, aux(tree, d, getPostId), *tree)
    //Posts_D r = g_tree_lookup(tree, getParentId2(pergunta));
      if(getPostType(r) == 2){
        val = valResposta(com, r);
        if(val > maxval){
          melhor = getPostId(r);
          maxval = val;
        }
      }
      respostas--;
      tree = r;
    }

  return melhor;
}
