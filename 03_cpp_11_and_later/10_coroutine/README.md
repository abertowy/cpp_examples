Coroutine
=========
  
возвращаемый тип `task`; отсутсвует в стандвртной библиотеке. Рекомендуется использовать CppCoro  
он сохраняет состояние сопрограммы (фактически фрейма стека функции) между вызовами и определяет значение `co_yield`.  
С точки зрения пользователя task тривиален, он просто предоставляет оператор для вызова сопрограммы:  
```
struct task {
  void operator()();
    // ... implementation details ...
}
```
  
```
struct task {
  void operator()() { coro.resume(); }
  struct promise_type {						// mapping to the language features
    suspend_always initial_suspend() { return {}; }
    suspend_always final_suspend() noexcept { return {}; }	// co_return
    suspend_always yield_value(int) { return {}; }		// co_yield
    auto get_return_object() { return task{ handle_type::from_promise(*this) }; }
    void return_void() {}
    void unhandled_exception() { exit(1); }
 };
  using handle_type = coroutine_handle<promise_type>;
  task(handle_type h) : coro(h) { }				// called by get_return_object()
  handle_type coro;						// here is the coroutine handle
};
```