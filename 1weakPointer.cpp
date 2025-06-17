#include<iostream>
#include<memory>

int main()
{
    std::shared_ptr<int>sp = std::make_shared<int>(43);
    // 🔍 What this does:
    // std::make_shared<int>(42) creates a NEW integer (int) with value 42, on the heap.
    // sp is a shared_ptr<int>, which owns this heap-allocated int.
    // shared_ptr keeps a reference count. Right now, it's 1.
    // ✅ Memory:
    // int(42) is stored on heap.
    // sp points to it and owns it.
    // Reference count = 1
    std::weak_ptr<int>wp = sp;
    /*
        🔍 What this does:
        wp is a weak_ptr<int>. It observes the same heap object as sp, but doesn’t own it.
        It does not increase the reference count.
        ✅ Memory:
        sp still owns the object.
        wp can look at it, but can’t keep it alive.
    */
    std::cout << "Use count: " << sp.use_count() << "\n"; 
    /*
    🔍 What this does:
    Prints how many shared_ptrs are currently owning the object.
    Output: Use count: 1
    ⚠️ weak_ptr does not affect this count. 
    */
   if(auto locked = wp.lock())
   {
        /*
        // wp.lock() tries to get a shared_ptr (named locked) from the weak_ptr.

        If the object is still alive (not deleted), lock() succeeds and returns a valid shared_ptr.If the object is still alive (not deleted), lock() succeeds and returns a valid shared_ptr.

        The if checks if locked is not null.

        ✅ locked is like a safe, temporary way to use the object only if it still exists.
        */

        std::cout << "Value: " << *locked << "\n";  // 42
        /*✅ At this point:
        Reference count is 2: sp + locked
        Value is still 42.*/
   }
    sp.reset();  // deletes object (reference count = 0)
    //Reference count now drops to 0 → memory on heap is freed automatically.
    // wp now points to nothing (expired).

    if (wp.expired()) {
        std::cout << "Object is gone!\n";
    }

}