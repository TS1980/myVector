class Array
{
	int* arr;
	int size;
public:
	// Default constructor
	Array()
	{
		arr = nullptr;
		size = 0;
	}

	// Copy constructor
	Array(Array &obj)
	{
		size = obj.size;
		arr = new int[size];
		memcpy(arr, obj.arr, size * sizeof(int));
	}

	// Destructor
	~Array()
	{
		delete[] arr;
	}

	void add(int data)
	{
		int* tmp = new int[size + 1];
		//for (int i = 0; i < size; i++)
		//{
		//	tmp[i] = arr[i];
		//}
		memcpy(tmp, arr, size * sizeof(int));
		delete[] arr;
		arr = tmp;
		arr[size] = data;
		size++;
	}

	void remove(int index)
	{
		int* tmp = new int[size - 1];
		int j = 0;
		for (int i = 0; i < size; i++)
		{
			if (i != index)
			{
				tmp[j++] = arr[i];
			}
		}
		delete[] arr;
		arr = tmp;
		size--;
	}

	void insert(int data, int index)
	{
		size++;
		int* tmp = new int[size];
		int j = 0;
		for (int i = 0; i < size; i++)
		{
			if (i != index)
			{
				tmp[i] = arr[j++];
			}
		}
		delete[] arr;
		arr = tmp;
		arr[index] = data;
	}

	int select(int index)
	{
		if (index >= 0 && index < size)
		{
			return arr[index];
		}
		else if (index >= size)
		{
			return arr[size - 1];
		}
		else if (index < 0)
		{
			return arr[0];
		}
	}

	int getSize()
	{
		return size;
	}
	
	void print()
	{
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
};
