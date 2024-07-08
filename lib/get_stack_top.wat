(module
  (global $__stack_pointer (import "env" "__stack_pointer") (mut i32))
  (func $getllvmallocastacktop (result i32)
    global.get $__stack_pointer
  )
  (export "getllvmallocastacktop" (func $getllvmallocastacktop))
)
