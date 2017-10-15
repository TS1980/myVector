template<typename T>
class mvector
{
	T* arr;
	int size;
public:
	// Default constructor
	mvector()
	{
		arr = nullptr;
		size = 0;
	}

	// Copy constructor
	mvector(mvector &obj)
	{
		size = obj.size;
		arr = new T[size];
		memcpy(arr, obj.arr, size * sizeof(T));
	}

	// Destructor
	~mvector()
	{
		delete[] arr;
	}

	void add(T data)
	{
		T* tmp = new T[size + 1];
		memcpy(tmp, arr, size * sizeof(T));
		delete[] arr;
		arr = tmp;
		arr[size] = data;
		size++;
	}

	void remove(int index)
	{
		T* tmp = new T[size - 1];
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

	void insert(T data, int index)
	{
		size++;
		T* tmp = new T[size];
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

	T select(int index)
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
