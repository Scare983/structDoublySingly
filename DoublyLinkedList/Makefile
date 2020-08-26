OBJS		= Main.o ItemType.o DoublyLinkedList.o
COMPILE		= g++ -g -c -std=gnu++0x -o $@

# the main target
main: $(OBJS)
	g++ -o $@ $(OBJS)
	
# dependencies
Main.o: Main.cpp
	$(COMPILE) Main.cpp
	
ItemType.o: ItemType.h ItemType.cpp
	$(COMPILE) ItemType.cpp
	
DoublyLinkedList.o: DoublyLinkedList.h  DoublyLinkedList.cpp
	$(COMPILE) DoublyLinkedList.cpp
	
clean:
	$(RM) $(OBJS)
	
cleanall: clean
	$(RM) main
