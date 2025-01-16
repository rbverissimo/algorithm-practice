//this is some naive implementation of string matching
#include<stdio.h>
#include<string.h>


void search(char* text, char* target){
	
	int M = strlen(target); //overall less than N
	int N = strlen(text);
	
	
	for(int i = 0; i < N - M; i++){  //N - M because if there are any text length with less chars the pattern itself, than there is no point on searching
		int j; 
		for(j = 0; j < M; j++){
			if(text[i + j] != target[j]) break;
		}
		if(j == M) printf("Target found at index %d\n",i);
	}
}


int main(){
	
	char text[] = "Fly me to the moon, let me play along the stars";
	char target[] = "th";
	
	printf("Searching for indexes there 'th' happens \n");
	//search(text, target);
	
	char another_text[] = "**Fly Me to the Moon: A Journey of Dreams and Love** 'Fly Me to the Moon' is more than just a beloved jazz standard; it's a timeless expression of love and longing that resonates in the hearts of many. The song, originally written by Bart Howard in 1954, captures the essence of romance, evoking a sense of adventure and the desire to escape to a place where love knows no boundaries. Its silky melodies and heartfelt lyrics have been interpreted by countless artists, but perhaps most famously by Frank Sinatra, whose rendition has become iconic. The phrase 'fly me to the moon' serves as a metaphor for transcending the everyday and reaching for something extraordinary. It speaks to the desire to share unforgettable moments with a loved one, to explore the cosmos together, and to experience the beauty of love in all its forms. The imagery evokes a dreamlike journey, transporting listeners to a realm where gravity fades away, and the stars become the backdrop for romance. In many ways, 'Fly Me to the Moon' embodies the spirit of exploration—both of the universe and of personal relationships. It reminds us that love can elevate us, pushing us beyond our limits and inspiring us to dream bigger. The moon, often associated with mystery and wonder, becomes a symbol of the heights we can reach when we dare to love deeply. As we listen to this classic tune, we are invited to reflect on our own journeys—those moments when we felt as if we were soaring through the sky, buoyed by the love of someone special. Whether at a wedding, a romantic dinner, or simply in the comfort of our homes, 'Fly Me to the Moon' has the power to transport us to a place where love reigns supreme, reminding us of the beauty that exists both in our relationships and in the cosmos above. So the next time you hear the sweet strains of this enchanting melody, let it inspire you to dream, to love, and to reach for the stars. After all, love is the ultimate adventure, and with the right partner, every moment can feel like a journey to the moon and back. --- Feel free to adjust or expand upon this text for your needs!";
	char another_target[] = "ov";
	search(another_text, another_target);
		
	return 0;
}

//this is a very costly algorithm

