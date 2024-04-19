#!/bin/sh

IMAGE_NAME="42_testing"

# Image exists
IMG_COUNT=$(docker image list -a --filter "reference=$(IMAGE_NAME)" -q | wc -l | tr -d ' ')

if [ $IMG_COUNT -gt 0 ]; then \
	echo "An image already exists"
	echo "Would you like to rebuild or run from the existing image?"
	select option in "Rebuild" "Use existing image"; do
    case $REPLY in
        1)
            echo "Rebuilding the image..."
            make reinstall
            break
            ;;
        2)
            echo "Using the existing image."
            break
            ;;
        *)
            echo "Invalid option. Please select 1 to rebuild or 2 to use the existing image."
            ;;
    esac
done

else \
	echo "Image doesn't exist"
	echo "Creating a new one..."
	make configure
	echo "Image created!"
fi

# Choose project
echo "Which project would you like to run?"
select option in "SO_LONG" "PIPEX" "CUSTOM"; do
    case $REPLY in
        1)
            echo "Running so_long..."
            cd docker && ./so_long.sh
            break
            ;;
        2)
            echo "Opening pipex..."
			cd pipex
			docker run -it -v $PWD:/cursus/pipex -w /cursus/pipex 42_testing
            break
            ;;
        *)
            echo "Chosen custom. Freeroam of the directory."
			docker run -it -v $PWD:/cursus -w /cursus 42_testing
			break
            ;;
    esac
done