object_files = Music_collection.o

output.txt : a.out
	./a.out > output.txt
	cp main.cpp ~/Downloads/main.cpp
	cp Music_collection.cpp ~/Downloads/Music_collection.cpp
	cp Music_collection.h ~/Downloads/Music_collection.h

a.out : Music_collection.o main.cpp
	g++ $(object_files)  main.cpp

Music_collection.o : Music_collection.cpp Music_collection.h
	g++ -c Music_collection.cpp

.PHONY : clean
clean :
	-rm $(object_files)
