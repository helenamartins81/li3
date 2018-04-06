#include "postsID.h"
#include <glib.h>
#include "data.c"


struct Posts_id
{
	long id_post;
	long id_user;
	char* titulo;
	Data data;
	struct Posts_id *esq, *dir;
}Posts_ID;

// Posts_ID createPosts_ID ()

long getPostId2 (Posts_ID posts){
	return posts->id_post;
}

long getUserId2 (Posts_ID posts){
	return posts->id_user;
}

char* getTitle2 (Posts_ID posts){
	return posts->titulo;
}

Date getDate2 (Posts_ID posts){
	return posts->data;
}
