from mpi4py import MPI
#mpiexec -np 2 python p.py 
comm = MPI.COMM_WORLD
rank = comm.Get_rank()

if rank == 0:
    print("Maestro")
elif rank == 1:
    print("Esclavo")