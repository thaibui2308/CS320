program TravelingSalesman

    implicit none

    !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    ! Variable declarations
    integer :: status, numCities, i, j, sum,sumMin, permutation = 0
    character(len = 50) :: filename 
    character(len = 10), dimension(:), allocatable :: cityName 
    integer, dimension (:, :), allocatable :: distanceTable
    integer, dimension (:), allocatable :: path, bestPath
    sumMin = 999999
    !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    ! File operations
    print *, "Enter File Name:"
    read *, filename 
    open(unit=10, file=filename, STATUS = "OLD", ACTION="READ", IOSTAT=status)
    if (status /= 0) then 
        print *, "File did not open correctly!"
        stop
    end if

    read(unit=10, fmt=100) numCities

    allocate(cityName(1:numCities))
    allocate(distanceTable(1:numCities, 1:numCities))
    allocate(path(1:numCities))
    allocate(bestPath(1:numCities))

    do i = 1, numCities
        path(i) = i
        bestPath(i) = i
        read(unit=10, fmt=200) cityName(i)
        do j = 1, numCities
            read(unit=10, fmt=100) distanceTable(i,j)
        end do
    end do

    200 format (A)
    100 format (I6)

    !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    ! Recursively find the best distance between cities.
    CALL permute(2, numCities)

    !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    ! Format output to the screen
    PRINT *, " "
    do i = 1, numCities  
        if (i/=numCities) then 
            print *, cityName(bestPath(i)), " to ", cityName(bestPath(i+1)), " -- ", distanceTable(bestPath(i),bestPath(i+1)), &
            " miles"
        else 
            print *, cityName(bestPath(i)), " to ", cityName(bestPath(1)), " -- ", distanceTable(bestPath(i), bestPath(1)), &
            " miles"
        end if 
    end do 
    print *, "Best distance is: ", sumMin, " miles"

    contains 
    ! subroutine
    recursive subroutine permute(first, last)
        implicit none
            integer :: first, last, tmp, j
            ! base case
            if (first == last) then 
                sum = distanceTable(1, path(2))
                do j = 2, (last-1)
                    sum = sum + distanceTable(path(j),path(j+1))
                end do
                ! Get distance from last city back home
                sum = sum + distanceTable(path(last), path(1))

                permutation = permutation + 1

                if (sum < sumMin) then 
                    sumMin = sum 
                    do j = 2 , numCities
                        bestPath(j) = path(j)
                    end do 
                end if
            else 
                ! mix it up
                do j = first, last 
                    tmp = path(first)
                    path(first) = path(j)
                    path(j) = tmp

                    ! recursion reduction step
                    call permute(first+1, last)

                    tmp = path(first)
                    path(first) = path(j)
                    path(j) = tmp
                end do
            end if
        return

    end subroutine permute

END PROGRAM TravelingSalesman