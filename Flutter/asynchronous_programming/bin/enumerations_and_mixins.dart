mixin CanJump{
  int get feetCount;

  void jump(){
    if(feetCount < 1){
      throw Exception('Can not jump');
    }else{
      print('Jumped!');
    }
  }
}  

enum AnimalType with CanJump {

  Cat(feetCount: 4),
  Man(feetCount: 2),
  Fish(feetCount: 0);

  @override
  final int feetCount;
  const AnimalType({required this.feetCount});
}

void main(){
  AnimalType.Cat.jump();
  AnimalType.Man.jump();
  AnimalType.Fish.jump();
}