//
//  BlockSintaxCheat.h
//  CesarLK
//
//  Created by Ivan on 9.05.17.
//
//

#ifndef BlockSintaxCheat_h
#define BlockSintaxCheat_h

//The cheat sheet from fuckingblocksyntax.com implemented as a bunch of mackrosses

//As a local variable:
//returnType (^blockName)(parameterTypes) = ^returnType(parameters) {...};
#define DefineBlockVariable(returnType,blockName, ...) returnType (^blockName)(__VA_ARGS__)

//As a property:
//@property (nonatomic, copy, nullability) returnType (^blockName)(parameterTypes);
#define BlockPropertyWithName(blockName, returnType, ...) returnType (^blockName)(__VA_ARGS__)

//As a method parameter:
//- (void)someMethodThatTakesABlock:(returnType (^nullability)(parameterTypes))blockName;
#define BlockArgumentType(returnType, ...) returnType (^)(__VA_ARGS__)

//As an argument to a method call:
//[someObject someMethodThatTakesABlock:^returnType (parameters) {...}];
#define Block(returnType,...) ^returnType (__VA_ARGS__)

//As a typedef:
//typedef returnType (^TypeName)(parameterTypes);
//TypeName blockName = ^returnType(parameters) {...};
//#define TypedefBlock(returnType,name,arguments) returnType(^name)(arguments); - no need cause existing xcode snipet

#define CreateBlockWithName(name,returnType,...) \
DefineBlockVariable(returnType,name,__VA_ARGS__) = Block(returnType,__VA_ARGS__)

#endif /* BlockSintaxCheat_h */
