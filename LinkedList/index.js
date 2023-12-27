class ListNode {
    constructor(data, next = null) {
      this.data = data;
      this.next = next;
    }
  }
  
  class LinkedList {
    constructor(head = null) {
      this.head = head;
    }
  
    append(data) {
      const newNode = new ListNode(data);
  
      if (!this.head) {
        this.head = newNode;
        return;
      }
  
      let current = this.head;
      while (current.next) {
        current = current.next;
      }
  
      current.next = newNode;
    }
  
    display() {
      console.dir(JSON.stringify(this.head));
    }
  
    reverse() {
      let current = this.head;
      let previous = null;
      let next = null;
  
      while (current !== null) {
        next = current.next;
        current.next = previous;
        previous = current;
  
        current = next;
      }
  
      this.head = previous
    }
  }
  
  const ll = new LinkedList();
  
  for(let i = 0; i < 10; i++) {
    ll.append(i+1);
  }
  
  
  ll.display();

  console.log("\n");
 
  ll.reverse();
  ll.display();
  