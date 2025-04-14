
class Database{
  bool _isOpen = false;

  Future<void> open(){
    return Future.delayed(
      Duration(seconds: 2), 
      () {
        _isOpen = true;
        print("Database opened! ");
      } 
    );
  }

  Future<void> close(){
    return Future.delayed(
      Duration(seconds: 5),
      () {
        _isOpen = false;
        print("Database closed! ");
      }
    );
  }

  Future<String> getData(){
    if(!_isOpen){
      throw DatabaseNotOpenException();
    }
    return Future.delayed( Duration(seconds: 2),
      () => "Data retrieved from the database"
    );
  }
}

class DatabaseNotOpenException implements Exception {
  @override
  String toString() {
    return 'Database not open';
  }
}

void main(List<String> args) async {

  /**
   * 
  Database db = Database();
  await db.open();
  db.getData().then((data) {
    print(data);
  })
  .catchError( (e) {
      print(e.toString());
    }
  );
  */
  String data;
  Database db = Database();
  try{
    await db.open();
    data = await db.getData();
    print(data);
  } on DatabaseNotOpenException {
    print("We forgot to open the database.");
  } finally {
    db.close();
  }
}