Exercise 03: Now it's weird! 

这是这个 Module 的 Boss 战：多重继承 (Multiple Inheritance)  和 菱形继承 (Diamond Problem)。


继承：DiamondTrap 要 同时 继承自 FragTrap 和 ScavTrap 。

语法是：class DiamondTrap : public ScavTrap, public FragTrap （或者 public FragTrap, public ScavTrap，顺序会影响一些默认行为，但在这里你需要显式处理所有冲突）。

核心问题 (The Trick)：

ScavTrap 和 FragTrap 都继承自 ClapTrap。

那 DiamondTrap 继承了它俩，是不是就有了 两个 ClapTrap 的“幽灵”实例（一个来自 ScavTrap，一个来自 FragTrap）？

题目明确说了："the ClapTrap instance of DiamondTrap will be created once, and only once. Yes, there's a trick." 

提示 (The Trick)：这个技巧叫做 虚拟继承 (Virtual Inheritance)。

你需要回去修改 Ex01 和 Ex02。让 ScavTrap 和 FragTrap 在继承 ClapTrap 时使用 virtual 关键字。

改成这样：class ScavTrap : virtual public ClapTrap 和 class FragTrap : virtual public ClapTrap。

这样，当 DiamondTrap 继承它俩时，C++ 就会知道它们共享同一个 ClapTrap 基类实例。

属性冲突 (Name)：


DiamondTrap 自己要有一个 private 的 name 属性 。

同时，它继承的那个 唯一 的 ClapTrap 实例里也有一个 name 属性。

题目要求：DiamondTrap 的构造函数接收一个 name，这个 name 用来设置 DiamondTrap 自己的 name ，同时 ClapTrap::name 要被设置为 name + "_clap_name" 。


构造函数 (重点)：

因为是虚拟继承，DiamondTrap 的构造函数现在必须 直接 调用最顶层基类 ClapTrap 的构造函数来初始化 ClapTrap::name 。

你的初始化列表会是这样的：DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)。然后在这个构造函数体里，再设置 DiamondTrap 自己的那个 name 属性 。

属性冲突 (HP, EP, AD)：


DiamondTrap 的 HP 用 FragTrap 的 (100) 。


DiamondTrap 的 EP 用 ScavTrap 的 (50) 。


DiamondTrap 的 AD 用 FragTrap 的 (30) 。

提示：你需要在 DiamondTrap 的构造函数里（初始化列表之后，函数体之中）手动设置这些值。

函数冲突 (attack)：

ScavTrap 和 FragTrap 都有 attack() 函数（或者说它们从 ClapTrap 继承了，但 ScavTrap 可能重写了它）。

当 DiamondTrap 调用 attack() 时，到底用谁的？题目说了，用 ScavTrap 的 attack() 。

提示：你需要在 DiamondTrap 类里重新实现 attack() 函数，然后在函数体内部，使用作用域解析符 :: 来明确调用 ScavTrap::attack()。

新功能 (whoAmI)：

实现 whoAmI() 。

它需要打印 DiamondTrap 自己的 name 和 ClapTrap::name 。

提示：打印 ClapTrap::name 时，你需要用 ClapTrap::name 这样的方式来访问，以区分 DiamondTrap 自己的 name。

总结一下，这个 Module 的核心就是：

protected 访问权限。

子类构造函数如何通过“成员初始化列表”调用父类构造函数。

构造和析构的顺序。

Ex03 的“虚拟继承” (virtual) 如何解决菱形继承问题。

Ex03 如何使用作用域解析符 (::) 来解决函数和属性的歧义。