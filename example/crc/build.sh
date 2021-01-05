#!/bin/bash

path_to_targets=$(pwd)/bsp
path_to_output=$(pwd)/out


function update_target_list {
  target_list=()

  for file in $path_to_targets/*
  do
    if [ -d "$file" ]; then
        if [ -f "$file/CMakeLists.txt" ]; then
          if [ -f "$file/.ignore" ]; then
            continue
          else
            target_list+=( $( basename $file ) )
          fi
        fi
    fi
  done
}



function build_target_with_cmake {
  local target=$1
  
  if [[ " ${target_list[@]} " =~ " ${target} " ]] || [ $target = "all" ]
  then
    for i in ${!target_list[@]}; do
      if [ $target = ${target_list[$i]} ] || [ $target = "all" ]
      then
        echo "-> Building project for target '${target_list[$i]}':"
        cmake $path_to_targets/${target_list[$i]}/CMakeLists.txt -B $path_to_output/${target_list[$i]}
        cmake --build $path_to_output/${target_list[$i]} --target all -- -j8
        echo ""
      fi
    done
  else
    echo "Target '$target' not found " 
  fi
}




update_target_list

while [ -n "$1" ]
do
  case "$1" in
    -h) echo "Key list: "
        echo "-h - print this message"
        echo "-l - print target list"
        echo "-c - remove output directory"
        echo "-b target_name/all - build targets" 
        echo "" ;;
        
    -l) echo "Finded targets: "
        for i in ${!target_list[@]}; do
          echo ${i}\) ${target_list[$i]} 
        done 
        echo "" ;;
               
    -b) target="$2"
        build_target_with_cmake $target
        shift ;;
        
    -c) echo "Remove output directory"
        rm -rf $path_to_output ;;
        
     *) echo "$1 is unknown option" ;;
  esac
  shift
done

