(module
  (memory 2)
  (func $memcpy (param $dst i32) (param $src i32) (param $len i32) (result i32)
    local.get $dst
    local.get $src
    local.get $len
    memory.copy
    local.get $dst
  )
)