#lang scheme
; p6.scm
; A prototype for program 6 in scheme
;
; Program 6
; CS-320-01-Fall-2021
; @12-1-2021
; @Thai Bui
;
; Edit this file to add your documentation and function definitions.
; Leave the rest of this file unchanged.
; To run this file, you would start scheme at edoras command line prompt:
; scheme --load p6.scm, where the file is in the current directory
; and then in scheme type the load command (from the '%' prompt):
;(load "p6.scm")
;
; Defined LISTS for use with testing your functions.

(define list0 (list 'j 'k 'l 'm 'n 'o 'j) )
(define list1 (list 'a 'b 'c 'd 'e 'f 'g) )
(define list2 (list 's 't 'u 'v 'w 'x 'y 'z) )
(define list3 (list 'j 'k 'l 'm 'l 'k 'j) )
(define list4 (list 'n 'o 'p 'q 'q 'p 'o 'n) )
(define list5 '((a b) c (d e d) c (a b)) )
(define list6 '((h i) (j k) l (m n)) ) 
(define list7 '(f (a b) c (d e d) (b a) f) )
(define list8 '())
(define atm0 10)
;
; Here is a typical function definition from Sebesta Ch. 15
(define (adder lis)
  (cond
    ((null? lis) 0)
	(else (+ (car lis) (adder (cdr lis))))
))
; The above five lines are the sort of definition you would need to add to
; this file if asked to define an ADDER function.
; Uncomment and complete the following five definitions. At least have ODDS
; so the program can be tested.

; (define (odds ... 
; returns a list containing the odd indexed elements of the passed list
(define (odds lst)
  (cond
    ((not (list? lst)) "USAGE: (odds {list})")
    ((null? lst) '())
    ((null? (cdr lst)) lst)
    (else (cons (car lst)(odds (cddr lst))))))
; (define (evenrev ...
; returns a list containing the even indexed elements of the passed list reversed
(define (evenrev lst)
  (cond
    ((not (list? lst)) "USAGE: (evenrev {list})")
    ((null? lst) '())
    ((null? (cdr lst)) '())
    
    (else(append (evenrev (cddr lst))(list (cadr lst)) ))
    ))

; (define (penultimate ...
; return the second last element of the list
(define (penultimate lst)
  (cond
    ((not (list? lst)) "USAGE: (penultimate {list})")
    ((null? (cdr lst)) '())
    ((null? lst) '())
    ((null? (cddr lst)) (list (car lst)))
    (else (penultimate (cdr lst)))))
; (define (palindrome ...
; return #t if the list is palindrome
(define (trim lst)
  (cdr (reverse (cdr (reverse lst)))))
(define (palindrome lst)
  (cond
    ((not (list? lst)) "USAGE: (palindrome {list})")
    ((null? lst) #t)
    ((null? (cdr lst)) #t)
    ((equal? (car lst) (last lst))(palindrome (trim lst)))
    (else #f)))
; (define (change-head ...
; returns the list generated by replacing the first element of the first list with the first element of the second list
(define (change-head lst1 lst2)
  (cond
    ( (or (not (list? lst1))
          (not (list? lst2)) )
      (display "Usage not a list") (newline))
    ( (null? lst1) (display "Usage list1 is null") (newline))
    ( (null? lst2) (display "Usage list2 is null") (newline))
    (else
     (cons (car lst2) (cdr lst1)))))
    
