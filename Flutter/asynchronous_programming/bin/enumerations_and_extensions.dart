enum AnimalType {
  cat, 
  dog,
  rabbit;

  void run(){
    print('$this is running ..');
  }
}

extension Jumping on AnimalType{
  void jump(){
    print('$this jumped !!');
  }
}

void main(){
  AnimalType.cat
  ..run()
  ..jump();
  print('');

  AnimalType.dog
  ..run()
  ..jump();
  print('');

  AnimalType.rabbit
  ..run()
  ..jump();
  print('');
}