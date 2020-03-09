# 几何图形交点项目运行说明

## 功能

从通过命令行指定的符合题目格式要求的文件中读取几何图形参数信息，并在指定的输出文件中输出上述几何图形交点的数量。

## 目录结构

```
SE_PSP_Project_17373187/
├── bin
│   └──  intersect.exe
│
├── README.md
├── src
│   ├── Main.cpp
│		├── Point.cpp
│   ├── Line.cpp
│   ├── Circle.cpp
│   ├── Point.h
│   ├── Line.h
│   └── Circle.h
│   
└── test
		├── PointTest.cpp
		├── LineTest.cpp
    └── CircleTest.cpp
```

## 设计思路

一共划分为3个类，分别是Point、Line、Circle。

- Point类
  - 成员变量：x，y，可见性为private。分别表示点的横纵坐标。
  - get方法，用于获取x，y变量。
  - 重写`<`运算符。
- Line类
  - 成员变量：x0，y0，x1，y1，可见性为private，表示直线经过的点，以及直线一般式中的参数a，b，c。
  - get方法。
  - getLineIntersectPoint。静态函数，用于求两直线的交点，并将其加入传入的集合。
- Circle类
  - 成员变量：x，y，r，可见性为private，表示圆的圆心坐标以及半径。
  - get方法。
  - getLineCircleIntersect。静态函数，用于求直线与圆的交点，并将其加入传入的集合。
  - getCircleIntersect。静态函数，用于求圆与圆的交点，并将其加入传入的集合。

最后，在main函数中，对输入参数进行解析，然后读取输入数据，将直线和圆分别进行保存。每次新增一个图形，就与其他的图形求交点。将所有交点保存在一个set里进行去重，最后输出set的大小。

## 使用说明

- 正常使用

  使用命令行进行调用。

  | 参数                       | 参数意义                                         | 用法示例                                   |
  | -------------------------- | ------------------------------------------------ | ------------------------------------------ |
  | `-i <path to input file>`  | 带一个参数，表示输入文件的路径（绝对或相对路径） | `intersect.exe -i input.txt -o output.txt` |
  | `-o <path to output file>` | 带一个参数，表示输出文件的路径（绝对或相对路径） | `intersect.exe -i input.txt -o output.txt` |

- 异常情况

  如果命令行没有指定或缺少对输入输出任何一个文件位置的指定，则程序输出：

  > ERROR: input/output file path is not specified.

  如果无法打开文件，则程序输出：

  > ERROR: failed to open files.

  如果指定的输入文件中出现不合法的标识符（L与C之外），则程序输出：

  > ERROR: invalid mark character.