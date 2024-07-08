(module
  (memory 2)
  (func $getmorepages (param $numpages i32) (result i32)
    local.get $numpages
    memory.grow
  )
  (export "getmorepages" (func $getmorepages))
)
