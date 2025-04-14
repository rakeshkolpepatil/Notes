void main(List<String> args){
  String str1 = "   ";
  String str2 = "Hello";
  String str3 = "";

  print(str1.isBlank); // Output: true (because it contains only whitespace)
  print(str2.isBlank); // Output: false (because it contains non-whitespace characters)
  print(str3.isBlank); // Output: true (because it's an empty string)
}

extension on String {
  // bool get isBlank => trim().isEmpty;
  
  // 'this' keyword is optional. 
  bool get isBlank => trim().isEmpty;
}