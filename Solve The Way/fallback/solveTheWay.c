#include<stdio.h>
#include<strings.h>
#include<stdlib.h>

// priv_key	~	The path found out
// pub_key	~	Team ID

int hasWon(long long priv_key, long long pub_key)
{
	FILE * keys = fopen("Paths", "r+");
	long long key = (priv_key * pub_key), cur_key;
	do
	{
		fscanf(keys, "%llu\n", &cur_key);
		if(cur_key == key)
		{
			fclose(keys);
			return 1;
		}
	}
	while(!feof(keys));
	fclose(keys);
	return 0;
}

int updatePosition(long long pub_key)
{
	FILE * pos = fopen("Positions", "rw+");
	long long team_id;
	short i = 1;
	do
	{
		fscanf(pos, "%llu\n", &team_id);
		if(team_id == pub_key)
		{
			fclose(pos);
			return i;
		}
		i++;
	}
	while(!feof(pos));
	fprintf(pos, "%llu\t%d\n", pub_key, i);
	fclose(pos);
	return i;
}
int main(int argc, char* args[])
{
	long long team_id, pathFound;
	if(argc != 3)
	{
		printf("Invalid Usage of command! Please enter the information manually below, as instructed.\n\nEnter Team ID:\t");
		scanf("%llu", &team_id);
		printf("Enter the Path Traversed:\t");
		scanf("%llu", &pathFound);
	}
	else
	{
		team_id = strtoull(args[1], NULL, 10);
		pathFound = strtoull(args[2], NULL, 10);
	}
	if(hasWon(pathFound, team_id))
		printf("Congratulations!!! You've come %d in Sole The Way 2017!!\n", updatePosition(team_id));
	else
		printf("I'm sorry, but either you've given incorrect inputs or you've got the wrong path. Please find out.\n");
}
