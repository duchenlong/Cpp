class FooBar {
private:
    int n;
    mutex _lock1;
    mutex _lock2;
public:
    FooBar(int n) {
        this->n = n;
        _lock2.lock();
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            _lock1.lock();
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            _lock2.unlock();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            _lock2.lock();
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            _lock1.unlock();
        }
    }
};


我们提供一个类：

class FooBar {
  public void foo() {
? ? for (int i = 0; i < n; i++) {
? ? ? print("foo");
?   }
  }

  public void bar() {
? ? for (int i = 0; i < n; i++) {
? ? ? print("bar");
? ? }
  }
}
两个不同的线程将会共用一个 FooBar?实例。其中一个线程将会调用?foo()?方法，另一个线程将会调用?bar()?方法。

请设计修改程序，以确保 "foobar" 被输出 n 次。

?

示例 1:

输入: n = 1
输出: "foobar"
解释: 这里有两个线程被异步启动。其中一个调用 foo() 方法, 另一个调用 bar() 方法，"foobar" 将被输出一次。
示例 2:

输入: n = 2
输出: "foobarfoobar"
解释: "foobar" 将被输出两次。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/print-foobar-alternately
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
